MEMORY
{
	rom (rx)  : ORIGIN = 0x08000000, LENGTH = 0x00004000
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00001000
}

SECTIONS
{
	.text :
	{
		KEEP(*(.vector_table))
		*(.text*)	
		*(.rodata*)
	} > rom
	
	.data :
	{
		. = ALIGN(4);
		*(.data*)
	} > ram
	
	.bss :
	{
		. = ALIGN(4);
		__bss_start__ = .;
		*(.bss*)
		. = ALIGN(4);
		__bss_end__ = .;
	} > ram
}