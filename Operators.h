/** @file  */

#pragma once

#include <iostream>

#include "Signs.h"

#include "Parameters.h"
#include "Primal.h"
#include "Borderer.h"
#include "Branch.h"
#include "Predecessor.h"
#include "DataTops.h"
#include "Graph.h"
#include "Solution.h"

std::ostream& operator<<(std::ostream&, Graph*&);
std::ostream& operator<<(std::ostream&, Borderer*&);
std::ostream& operator<<(std::ostream&, DataTops*&);
std::ostream& operator<<(std::ostream&, Primal*&);
std::ostream& operator<<(std::ostream&, Branch*&);
std::ostream& operator<<(std::ostream&, Solution*&);