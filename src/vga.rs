use core::fmt;

#[allow(dead_code)]
#[allow(non_camel_case_types)]
#[derive(Clone, Copy, Debug, Eq, PartialEq)]
#[repr(u8)]
pub enum ColourEnum {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    Light_grey = 7,
    Dark_grey = 8,
    Light_blue = 9,
    Light_green = 10,
    Light_cyan = 11,
    Light_red = 12,
    Pink = 13,
    Yellow = 14,
    White = 15,
} 

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
#[repr(transparent)]
pub struct CreateColourCode(u8);

impl CreateColourCode {
    fn make(background_colour: ColourEnum, foreground_colour: ColourEnum) -> u8 {
        ((background_colour as u8) << 4) | (foreground_colour as u8)
    }
}

pub struct Ttywrite {
    current_col_marker: usize,
    colour: u8,
    tty_buffer: *mut u8,
}

impl Ttywrite {
    pub fn write_byte(&mut self, byte_to_write: u8) -> () {
        //(self.current_col_marker>2000).then_some(self.current_col_marker = 0);
        unsafe { 
            *self.tty_buffer.offset(self.current_col_marker as isize *2) = byte_to_write;
            *self.tty_buffer.offset(self.current_col_marker as isize *2+1) = self.colour as u8;
        }
        self.current_col_marker += 1;
    }
    pub fn write_string(&mut self, string_to_write: &str) -> () {
        for char in string_to_write.bytes() {
            match char {
                32_u8..=255_u8 => self.write_byte(char),
                _ => self.write_byte(b' '),
            }
        }
    }
}

impl fmt::Write for Ttywrite {
    fn write_str(&mut self, string_to_write: &str) -> fmt::Result {
        self.write_string(string_to_write);
        Ok(())
    }
}

#[macro_export]
macro_rules! print {
    ($($arg:tt)*) => ($crate::vga::_print(format_args!($($arg)*)));
}

#[doc(hidden)]
pub fn _print(arguments: fmt::Arguments) {
    use core::fmt::Write;
    let mut printer = Ttywrite {
        current_col_marker: 0,
        colour: CreateColourCode::make(ColourEnum::Black, ColourEnum::Red),
        tty_buffer: 0xb8000 as *mut u8,
    };
    write!(printer, "{}", arguments).unwrap();
}
