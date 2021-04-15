#include "print.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("   NNNN ////        NNNN  ****       ****    *********   TTTTTTTTTTTTT\n   NNNN  ////       NNNN  ****       ****    *******        TTTTTT\n   NNNN   ////      NNNN  ****       ****    **               TT\n   NNNN    ////     NNNN  ****       ****    **               TT\n   NNNN     ////    NNNN  ****       ****       *****         TT\n   NNNN      ////   NNNN    **********         *******        TT\n   NNNN       ////  NNNN      ******         ********         TT");
}
