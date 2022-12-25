#ifndef CFG_H
#define CFG_H
#include<iostream>
using namespace std;

/**
 * <main> -> { <block> | <statement> | <list_statement> }
 * <block> -> { <block> | <statement> | <list_statement> }
 * <list_statement> -> <statement> | <statement> <statement> ...
 * <statement> -> <create_object>. | <assign_object>. | <control_flow> | <loop>
 * <create_object> -> <data_type> <name>. | <data_type> <name> = <date_type>:value.
 * <assign_object> -> <name> = <data_type>:value.
 * <data_type> -> <class>:value | <int>:value | <float>:value | <string>:value | <complex>:value
 * <control_flow> -> (if | else | if else) (<expression>) { <list_statement>}
 * <loop> -> <for_loop> | <while_loop> | <do_while_loop>
 * <for_loop> -> for (<create_variable> | NULL, <condition>, <operation>) {<list_statement>}
 * <while_loop> -> while(<expression)
 *
 *
 */




#endif