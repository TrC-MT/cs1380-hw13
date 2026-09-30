/*
    Author: Travis Cook
    Purpose/Function: Links the two .c files and stores the function prototypes
    Title: cafe.h
*/

#ifndef CAFE_H
#define CAFE_H

#define CAFE_OK 0
#define CAFE_ERR_NULL -1
#define CAFE_ERR_BAD_AMOUNT -2
#define CAFE_ERR_INSUFFICIENT -3

void preview_discount(int price_cents, int percent_off);
void apply_discount(int *price_cents, int percent_off);
int charge(int balance_cents, int cost_cents, int *new_balance);
bool make_change(int paid_cents, int cost_cents, int *change_out);
bool price_span(const int prices[], int n, int *min_out, int *max_out);
void print_line_item(const char *name, int price_cents);

#endif




/*
Learning problem:  You are writing helpers for a small campus cafe register that works in integer cents (so $3.50 is 350). No floating-point money.

Split the interface from the implementation

cafe.h — include guard and prototypes
cafe.c — #include "cafe.h" and the definitions
main.c — #include "cafe.h" and the demo that calls the library (Part B)
Required functions (names must match):

void preview_discount(int price_cents, int percent_off); — compute a discounted price locally and print it. Do not change the caller’s price_cents.
void apply_discount(int *price_cents, int percent_off); — if price_cents is not NULL and percent_off is in 0…100, update *price_cents in place. If the pointer is NULL, do nothing.
Error codes (macros or an equivalent set of #defines):
CAFE_OK = 0
CAFE_ERR_NULL = -1
CAFE_ERR_BAD_AMOUNT = -2
CAFE_ERR_INSUFFICIENT = -3
int charge(int balance_cents, int cost_cents, int *new_balance); —
CAFE_ERR_NULL if new_balance is NULL
CAFE_ERR_BAD_AMOUNT if balance_cents < 0 or cost_cents < 0
CAFE_ERR_INSUFFICIENT if cost_cents > balance_cents
otherwise store balance_cents - cost_cents in *new_balance and return CAFE_OK
bool make_change(int paid_cents, int cost_cents, int *change_out); — return false if change_out is NULL, if either amount is negative, or if paid_cents < cost_cents; otherwise store the change and return true
bool price_span(const int prices[], int n, int *min_out, int *max_out); — return false if n <= 0 or either output pointer is NULL; otherwise find the cheapest and most expensive prices and return true
void print_line_item(const char *name, int price_cents); — void helper that prints one labeled line (for example latte: 350 cents)
Requirements:

Keep the include guard in cafe.h. Put a short file docstring at the top of each .c file (what it does; your name).
Each function does one job. Prefer parameters and locals — no globals for money.
Discount math: new price = price_cents - (price_cents * percent_off) / 100 using integer arithmetic.
Compile with: //THIS IS BLANK IN THE INSTRUCTIONS
Why do all this?

preview_discount vs apply_discount makes pass by value vs pointer updates impossible to miss.
charge and make_change force you to check before you write through a pointer, and to tell the caller what went wrong.
price_span is how C returns “more than one value”: status plus outputs.

*/