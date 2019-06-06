#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLANK '_'
#define LEFT 'L'
#define RIGHT 'R'
#define STAY 'S'

typedef struct lista_s{
    char output, testina;
    int stato2;
    struct lista_s *next;
}lista_t;

typedef struct el_queue_s{
    int stato, i_pos, line_len, tape_len;
    char *line;
    char *ltape;
    long cont_mosse;
    struct el_queue_s *next;
}el_queue_t;

typedef struct queue_s{
    el_queue_t *head;
    el_queue_t *tail;
}queue_t;

typedef struct stati_s{
    int flagacc;
    lista_t **cinput;
    size_t dimcinput;
}stati_t;


char *str;    
char *strleft;  
size_t str_len; 

size_t ltape_len;  

stati_t *stati;     
size_t dimstati;    

char *caratteri;    
size_t dimcaratteri;  

int slen;
long maxcomp, cont;
queue_t queue, wait_list;
lista_t *p = NULL;

