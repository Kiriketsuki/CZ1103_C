//qn 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct circle {
    double radius;
    double x;
    double y;
};

//a

int intersect(struct circle c1, struct circle c2) {
    float x_dist = abs(c1.x - c2.x);
    float y_dist = abs(c1.y - c2.y);
    double radii = c1.radius + c2.radius;

    float distance = pow((pow(x_dist, 2) + pow(y_dist, 2)),0.5);

    if (distance <= radii) {
        return 1;
    } else {
        return 0;
    }
}

//b 

int contain(struct circle *c1, struct circle *c2) {
    struct circle *c1pt = c1;
    struct circle *c2pt = c2;

    float x_dist = abs(c1pt->x - c2pt->x);
    float y_dist = abs(c1pt->y - c2pt->y);
    double radii = c1pt->radius + c2pt->radius;

    float distance = pow((pow(x_dist, 2) + pow(y_dist, 2)),0.5);

    if (c1pt->radius >= (distance + c2pt->radius)) {
        return 1;
    } else {
        return 0;
    }

}

//qn 2

typedef struct {
    float operand1, operand2;
    char op;
} bexpression;

//a

float compute1(bexpression expr) {
    if (expr.op == '+') {
        return (expr.operand1 + expr.operand2);
    } else if (expr.op == '-') {
        return (expr.operand1 - expr.operand2);
    } else if (expr.op == '*') {
        return (expr.operand1 * expr.operand2);
    } else if (expr.op == '/') {
        return (expr.operand1 / expr.operand2);
    } else {
        printf("Invalid expression.\n");
        return;
    }
}

//b

float compute2(bexpression *expr) {
    bexpression *pt = expr;
    if (pt->op == '+') {
        return (pt->operand1 + pt->operand2);
    } else if (pt->op == '-') {
        return (pt->operand1 - pt->operand2);
    } else if (pt->op == '*') {
        return (pt->operand1 * pt->operand2);
    } else if (pt->op == '/') {
        return (pt->operand1 / pt->operand2);
    } else {
        printf("Invalid expression.\n");
        return;
    }
}

//qn 3

typedef struct {
    int id;
    int total_leave;
    int leave_taken;
} leave_record;

//a

void get_input(leave_record list[], int *n) {
    for (int i = 0; i < *n; i++) {
        printf("Please enter staff's ID\n");
        scanf("%d", &list[i].id);
        printf("Please enter #%d's total number of leave\n", list[i].id);
        scanf("%d", &list[i].total_leave);
        printf("Please enter amount of leave taken by #%d", list[i].id);
        scanf("%d", &list[i].leave_taken);
    }
}

//b 
