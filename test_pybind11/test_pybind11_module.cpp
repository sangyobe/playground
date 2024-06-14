#include <pybind11/pybind11.h>
#include "test_pybind11.hpp"

namespace py = pybind11;

PYBIND11_MODULE(test_pybind11_module, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: test_pybind11_module

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

    m.attr("__version__") = "0.0.1.dev";
}
