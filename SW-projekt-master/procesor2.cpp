#include <systemc.h>
#include "SignalWrite.h"

SC_MODULE(procesor2) {

    sc_inout<sc_uint<16>> state;

    void task8() {
        int sw = state->read();
        if (sw == 6)
        {
            Write(sw, sw);
        }
    }

    SC_CTOR(procesor2) {
        SC_METHOD(task8);
        sensitive << state;
    }
};