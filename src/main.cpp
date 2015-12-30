// Copyright (c) 2015 Thiago Pereira Bueno
// All Rights Reserved.
//
// This file is part of DBN library.
//
// DBN is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// DBN is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with DBN.  If not, see <http://www.gnu.org/licenses/>.

#include "variable.h"
#include "io.h"
#include "operations.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace dbn;

int main(int argc, char *argv[])
{
    unsigned order;
    std::vector<std::unique_ptr<Variable> > variables;
    std::vector<std::unique_ptr<Factor> > factors;

    read_uai_model(order, variables, factors);

    std::unique_ptr<Factor> f1 = product(*(factors[0]), *(factors[1]));
    std::cout << *f1 << std::endl;
    double prob = 0.0;
    for (int i = 0; i < f1->size(); ++i) {
        prob += (*f1)[i];
    }
    std::cout << "P(True) = " << prob << std::endl;

    std::unique_ptr<Factor> f2 = product(*(f1), *(factors[2]));
    std::cout << *f2 << std::endl;
    prob = 0.0;
    for (int i = 0; i < f2->size(); ++i) {
        prob += (*f2)[i];
    }
    std::cout << "P(True) = " << prob << std::endl;

    std::unique_ptr<Factor> f3 = product(*(f2), *(factors[3]));
    std::cout << *f3 << std::endl;
    prob = 0.0;
    for (int i = 0; i < f3->size(); ++i) {
        prob += (*f3)[i];
    }
    std::cout << "P(True) = " << prob << std::endl;

    return 0;
}
