/*
    Author: Travis Cook
    Purpose/Function: The user's interface with the program 
    Title: main.c
    The program must show:
        The same starting price used with preview_discount and then apply_discount, printing the price before/after so the difference is obvious.
        At least one successful charge and one failed charge (insufficient funds or bad amount), printing the error code.
        A successful make_change and a failing one.
        price_span on a small hard-coded price list, plus one failing call (n == 0 or a NULL output).
        At least one call to print_line_item.
*/

#include <stdio.h>
#include "cafe.h"


int main(){
    int prices[] = {350, 400, 120, 368};
    int percent_discount = 15;
    int balance = 1000;
    int new_balance;
    int change;
    int min_price;
    int max_price;
    int result;
    bool success;
    char name[] = "Hot-Chocolate";

    preview_discount(prices[0], percent_discount);
    apply_discount(&prices[0], percent_discount);
    printf("after apply_discount: %d\n", prices[0]);

    result = charge(balance, prices[1], &new_balance);
    printf("charge ok: code %d, %d - %d -> %d\n", result, balance, prices[1], new_balance);
    result = charge(balance, -4, &new_balance);
    printf("charge fail: code %d\n", result);

    success = make_change(350, prices[2], &change);
    printf("make_change success: %d\n", success);
    printf("change for %d on %d: %d cents\n", 350, prices[2], change);
    success = make_change(-31, prices[2], &change);
    printf("make_change success: %d\n", success);
    printf("change for %d on %d: %d cents\n", -31, prices[2], change);
    
    success = price_span(prices, 4, &min_price, &max_price);
    printf("price_span success: %d\n", success);
    printf("price span: min=%d max=%d\n", min_price, max_price);
    success = price_span(prices, 0, &min_price, &max_price);
    printf("price_span success: %d\n", success);
    // printf("price span: min=%d max=%d\n", min_price, max_price); // Would just show the leftover values of previous call

    print_line_item(name, prices[3]);

    return 0;
}