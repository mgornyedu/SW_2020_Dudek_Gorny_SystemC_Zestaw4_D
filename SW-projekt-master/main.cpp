#include <systemc.h>
#include "slider.cpp"
#include "szyna.cpp"
#include "procesor1.cpp"
#include "procesor2.cpp"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> clock;
	sc_signal<sc_uint<16>, SC_MANY_WRITERS> state;
	sc_signal<sc_uint<16>, SC_MANY_WRITERS> nasz_modul;
	szyna szyna("szyna");

	slider s("s");
	procesor1 p1("p1");
	procesor2 p2("p2");

    s.clock(clock);
	s.out(szyna.avalon);
    p1.clock(clock);
	p1.slider(szyna.avalon); 
	p1.state(state); 
    p2.state(state);

	p1.modul_out(nasz_modul);
    //sc_start();
    while (true)
    {
        clock.write(1);
        sc_start(1, SC_NS);
        clock.write(0);
        sc_start(1, SC_NS);
    }

	return 0;

}