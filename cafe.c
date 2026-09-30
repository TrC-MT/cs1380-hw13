/*
    Author: Travis Cook
    Purpose/Function: The calculations for the main program.
    Title: cafe.c
*/

#include <stdio.h>
#include "cafe.h"

void preview_discount(int price_cents, int percent_off){
    int discounted_price_prev;
    discounted_price_prev = price_cents - (price_cents * percent_off) / 100;
    printf("preview %d @ %d%%: %d (caller still %d)\n", price_cents, percent_off, discounted_price_prev, price_cents);
}


void apply_discount(int *price_cents, int percent_off){
    if(price_cents != NULL && percent_off >= 0 && percent_off <= 100){
       *price_cents = *price_cents - (*price_cents * percent_off) / 100;
    }
    else{} // else do nothing
}

int charge(int balance_cents, int cost_cents, int *new_balance){
    if(new_balance == NULL){
        return CAFE_ERR_NULL;
    }
    else if(balance_cents < 0 || cost_cents < 0){
        return CAFE_ERR_BAD_AMOUNT;
    }
    else if (cost_cents > balance_cents){
        return CAFE_ERR_INSUFFICIENT;
    }
    else{
        *new_balance = balance_cents - cost_cents;
        return CAFE_OK;
    }
}

bool make_change(int paid_cents, int cost_cents, int *change_out){
    if(change_out == NULL || paid_cents < 0 || cost_cents < 0 || paid_cents < cost_cents){
        return false;
    }
    else{
        *change_out = paid_cents - cost_cents;
        return true;
    }
}

bool price_span(const int prices[], int n, int *min_out, int *max_out){
    if(n <= 0 || min_out == NULL || max_out == NULL){
        return false;
    }
    else{
        *min_out = prices[0];
        *max_out = prices[0];
        for (int i = 0; i < n; i++)
        {
            if(prices[i] < *min_out){
                *min_out = prices[i];
            }
            else if(prices[i] > *max_out){
                *max_out = prices[i];
            }
        }
        return true;
    }
}

void print_line_item(const char *name, int price_cents){
    printf("%s: %d cents\n", name, price_cents);
}