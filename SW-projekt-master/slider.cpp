#include <systemc.h>
#include <iostream>
#include <conio.h>

SC_MODULE(slider) {
    sc_fifo_out<int> out;
    sc_in_clk clock;

    void read() {
        int val = 1;
        int sw = 0;
        char key_code;
        while (1)
        {
            if (_kbhit())
            {
                key_code = getch();
                val = atoi(&key_code);
                int s1 = 1 << (val - 1);
                if (sw & s1)
                    sw ^= s1;
                else
                    sw |= s1;
                out.write(sw);
                wait(10, SC_NS);
            }
            else
                out.write(sw);
        }
    }

    SC_CTOR(slider)
    {
        SC_CTHREAD(read, clock.neg());
    }

};