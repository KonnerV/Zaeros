#![no_std]
#![no_main]
#![feature(exclusive_range_pattern)]
#![feature(asm)]

use core::panic::PanicInfo;

mod vga;
mod abort;

#[panic_handler]
pub fn panic(_info: &PanicInfo) -> ! {
    print!("Panic enabled! Information: {}", _info); 
    loop{} 
}

#[no_mangle]
pub extern "C" fn _start() -> ! {
    print!("Hello, WorldTestttestA");
    abort();
    loop {}
}
