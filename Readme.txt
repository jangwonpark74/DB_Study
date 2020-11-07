Study PostgreSQL DB library for C++ : libpqxx

                                    -2020. 11. 08.

Reference URL : http://pqxx.org/development/libpqxx/
                https://gitee.com/funix/libpqxx
                https://www.tutorialspoint.com/postgresql/postgresql_c_cpp.htm

0) install in ubuntu 20.04
    

1) Building program using library
   g++ xxxx.cpp  -lpqxx -lpq   <- order should be kept. 

2) Header file include 

   #include <pqxx/pqxx>

3) Programming with libpqxx 

Your first program will involve the libpqxx classes "connection" (see headers
"pqxx/connection_base.hxx" and "pqxx/connection.hxx"), and "work" (a convenience
typedef for transaction<> which conforms to the interface defined in
"pqxx/transaction_base.hxx").

These "*.hxx" headers are not the ones you include in your program.  Instead,
include the versions without filename suffix (i.e. "pqxx/connection_base" etc.)
and they will include the .hxx files for you.  This was done so that includes
are in standard C++ style (as in <iostream> etc.), but an editor will still
recognize them as files containing C++ code.

Continuing the list of classes, you will most likely also need the result class
("pqxx/result.hxx").  In a nutshell, you create a "connection" based on a
Postgres connection string (see below), create a "work" in the context of that
connection, and run one or more queries on the work which return "result"
objects.  The results are containers of rows of data, each of which you can
treat as an array of strings: one for each field in the row.  It's that simple.

4) Realtime Analytic with PostgreSQL
- URL : https://www.youtube.com/watch?v=daeUsVox8hs
