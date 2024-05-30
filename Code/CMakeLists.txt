cmake_minimum_required(VERSION 3.28)
project(Projet)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projet main.cpp
        Date.h
        Deal.cpp
        Deal.h
        Entreprise.cpp
        Entreprise.h
        Lender.cpp
        Lender.h
        Agent.cpp
        Agent.h
        Borrower.cpp
        Borrower.h
        Facility.cpp
        Facility.h
        Date.cpp
        Portfolio.cpp
        Portfolio.h
)
