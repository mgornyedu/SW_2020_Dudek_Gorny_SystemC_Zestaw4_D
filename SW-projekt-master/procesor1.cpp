#include <systemc.h>
#include "SignalWrite.h"

SC_MODULE(procesor1) {

    sc_in_clk clock;
    sc_port<sc_fifo_in_if<int> > slider;
    sc_inout<sc_uint<16>> state;
    sc_out<sc_uint<16>> modul_out;
    int task2_state;
    int task2_sec;
    void task1() {
        int old_state = 0;
        int new_state = 0;
        int sw = 0;
        while (1) {
            int sw = slider->read();
            state->write(sw);
        }
    }

    void task2() {
        int sw = state->read();
        if (sw == 0 || sw == 4)
        {
            Write(sw, sw);
        }
    }

    void task3() {
        int sw = state->read();
        if (sw == 2)
        {
            Write(sw, sw);
        }
    }

    void task4() {
        int sw = state->read();
        if (sw == 3 || sw == 7)
        {
            Write(sw, sw);
        }
    }


    void task5() {
        int sw = state->read();
        if (sw == 1 || sw == 5)
        {
            int ps = sc_time_stamp().value();
            sc_time t(ps, SC_MS);
            int sec = t.to_seconds();
            if (task2_state == 0 && task2_sec == -1)
            {
                task2_sec = sec;
                task2_state = 1;
            }
            else if (task2_state == 2 && (sec - task2_sec) >= 3000) {
                task2_sec = -1;
                Write(state->read(), state->read());
                task2_state = 0;
            }
            else if (task2_state == 1 && (sec - task2_sec) >= 1500)
            {
                task2_state = 2;
                Write(state->read(), -1);
            }
        }
    }


    SC_CTOR(procesor1)  {
        task2_state = 0;
        task2_sec = -1;
        SC_THREAD(task1);
        sensitive << state;
        SC_METHOD(task2);
        sensitive << state;
        SC_METHOD(task3);
        sensitive << state;
        SC_METHOD(task4);
        sensitive << state;
        SC_METHOD(task5);
        sensitive << clock.pos();
    }
};
