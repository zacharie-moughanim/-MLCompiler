#ifndef LAMBDA_H
#define LAMBDA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum built_in_pseudo_type {
    L_LIST,
    L_CPL,
    L_BOOL
} built_in_pseudo_type_t;


typedef enum type {
    APPL,
    ABSTR,
    VAR
} type_lambda_t;

typedef struct lambda {
    type_lambda_t type;
    union lambda_content {
        // Variable
        char* var_name;

        // Application
        struct application_l {
            struct lambda* applying;
            struct lambda* to;
        } appl;

        // Abstraction
        struct abstraction {
            char* var_name;
            struct lambda* body;
        } abst;
    } content;
} lambda_term_t;

lambda_term_t* code_gen(ml_term_t* parsed_code);
void free_lambda_term(lambda_term_t* T);
void print_lambda_term(lambda_term_t* T, int indent, bool shift);

#endif // LAMBDA_H