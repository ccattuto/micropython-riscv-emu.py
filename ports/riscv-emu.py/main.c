#include "py/compile.h"
#include "py/runtime.h"
#include "shared/runtime/pyexec.h"
#include "py/stackctrl.h"
#include "py/gc.h"
#include <reent.h>

extern struct _reent *_impure_ptr;
extern uint8_t _gc_heap_start, _gc_heap_end;

int main(void) {
	__sinit(_impure_ptr);

    mp_stack_ctrl_init();
    mp_stack_set_limit(4096);
    gc_init((void*) &_gc_heap_start, (void*) &_gc_heap_end);
    mp_init();

    mp_printf(&mp_plat_print, "Welcome to MicroPython on RISC-V!\n");

	pyexec_friendly_repl();

    mp_deinit();
    return 0;
}

