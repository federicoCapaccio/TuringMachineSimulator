#include "main.h"

int main(){                                                                                               /* MAIN */

    int stato1, stato2, statoacc, i, j, dimcheck, fnd, res, getline_res, mem;         
    char input, output, testina;
    lista_t *t_nuovo = NULL;
    el_queue_t *nuovo = NULL, *tmp = NULL;

    queue.head = NULL;
    queue.tail = NULL;
    wait_list.head = NULL;
    wait_list.tail = NULL;
    stato1 = 0;
    stato2 = 0;
    statoacc = -1;
    i = 0;
    mem = 0;
    j = 0;
    dimcheck = -1;
    maxcomp = 0;
    fnd = 0;
    res = -1;
    slen = 0;
    input = 'a';
    output = 'a';
    testina = 'S';
    
    getline_res = getline(&str, &str_len, stdin); 
    
    getline_res = getline(&str, &str_len, stdin);     
    sscanf(str, "%d %c %c %c %d", &stato1, &input, &output, &testina, &stato2);

    if(stato1 > stato2){        
        dimstati = stato1 + 1;      
        stati = (stati_t *)malloc(dimstati * sizeof(stati_t));
    }else{
        dimstati = stato2 + 1;      
        stati = (stati_t *)malloc(dimstati * sizeof(stati_t));
    }

    for(i = 0; i < dimstati; i++){    
        stati[i].dimcinput = 0;
        stati[i].flagacc = 0;
        stati[i].cinput = NULL;
    }

    dimcaratteri = 1;       
    
    caratteri = (char *)malloc(dimcaratteri * sizeof(char));
    caratteri[0] = input;    

    stati[stato1].dimcinput = dimcaratteri; 
    stati[stato1].cinput = (lista_t **)malloc(stati[stato1].dimcinput * sizeof(lista_t *));

    stati[stato1].cinput[0] = NULL;

    t_nuovo = (lista_t *)malloc(sizeof(lista_t));
    t_nuovo->output = output;
    t_nuovo->testina = testina;
    t_nuovo->stato2 = stato2;
    t_nuovo->next = stati[stato1].cinput[0];
    stati[stato1].cinput[0] = t_nuovo; 
    getline_res = getline(&str, &str_len, stdin);
    sscanf(str, "%d %c %c %c %d", &stato1, &input, &output, &testina, &stato2); 

    while(strcmp(str, "acc\n")){
        dimcheck = dimstati;

        if((stato1 >= stato2) && stato1 >= dimstati){   

            dimstati = stato1 + 1; 
            stati = (stati_t *)realloc(stati, dimstati*sizeof(stati_t));

            for(i = dimcheck ; i < dimstati; i++){

                stati[i].dimcinput = 0;
                stati[i].flagacc = 0;
                stati[i].cinput = NULL;
            }
        }
        if((stato2 > stato1) && stato2 >= dimstati){

            dimstati = stato2 + 1;
            stati = (stati_t *)realloc(stati, dimstati*sizeof(stati_t));
            for(i = dimcheck ; i < dimstati; i++){
                stati[i].dimcinput = 0;
                stati[i].flagacc = 0;
                stati[i].cinput = NULL;
            }
        }
        
        if(stati[stato1].dimcinput == 0){     
            for(i = 0, fnd = 0; i < dimcaratteri && !fnd; i++){
                if(caratteri[i] == input)              
                    fnd = 1;
            }

            if(!fnd){
                dimcaratteri++;
                caratteri = (char *)realloc(caratteri, dimcaratteri * sizeof(char));
                caratteri[i] = input;   
            }else{
                i--;
            }

            stati[stato1].cinput = (lista_t **)malloc(dimcaratteri * sizeof(lista_t *)); 

            for (j = 0; j < dimcaratteri; j++){   
                stati[stato1].cinput[j] = NULL;
            }
            stati[stato1].dimcinput = dimcaratteri;
            
            if(stati[stato1].cinput[i]!= NULL){
                t_nuovo = (lista_t *)malloc(sizeof(lista_t));
                t_nuovo->output = output;
                t_nuovo->testina = testina;
                t_nuovo->stato2 = stato2;
                t_nuovo->next = stati[stato1].cinput[i];
                stati[stato1].cinput[i] = t_nuovo;
            }else{
                stati[stato1].cinput[i] = (lista_t *)malloc(sizeof(lista_t));
                stati[stato1].cinput[i]->output = output;
                stati[stato1].cinput[i]->testina = testina;
                stati[stato1].cinput[i]->stato2 = stato2;
                stati[stato1].cinput[i]->next = NULL;
            }


        }else{
            for(i = 0, fnd = 0; i < dimcaratteri && !fnd; i++){
                if(caratteri[i] == input)            
                    fnd = 1;
            }

            if(!fnd){
                dimcaratteri++;
                caratteri = (char *)realloc(caratteri, dimcaratteri * sizeof(char));
                caratteri[i] = input; 
                
                stati[stato1].cinput = (lista_t **)realloc(stati[stato1].cinput, dimcaratteri * sizeof(lista_t *));
                j = stati[stato1].dimcinput;   
                while(j < dimcaratteri){
                    stati[stato1].cinput[j] = NULL;
                    j++;
                }
                stati[stato1].dimcinput = dimcaratteri;
            }else{
                i--;
                if(i >= stati[stato1].dimcinput){
                    stati[stato1].cinput = (lista_t **)realloc(stati[stato1].cinput, dimcaratteri * sizeof(lista_t *));
                    j = stati[stato1].dimcinput;   
                    while(j < dimcaratteri){
                        stati[stato1].cinput[j] = NULL;
                        j++;
                    }
                stati[stato1].dimcinput = dimcaratteri;
                }
            }
            
            //instesta
            if(stati[stato1].cinput[i] != NULL){
                t_nuovo = (lista_t *)malloc(sizeof(lista_t));
                t_nuovo->output = output;
                t_nuovo->testina = testina;
                t_nuovo->stato2 = stato2;
                t_nuovo->next = stati[stato1].cinput[i];
                stati[stato1].cinput[i] = t_nuovo;
            }else{
                stati[stato1].cinput[i] = (lista_t *)malloc(sizeof(lista_t));
                stati[stato1].cinput[i]->output = output;
                stati[stato1].cinput[i]->testina = testina;
                stati[stato1].cinput[i]->stato2 = stato2;
                stati[stato1].cinput[i]->next = NULL;
            }
            
            
        }
        getline_res = getline(&str, &str_len, stdin);
        sscanf(str, "%d %c %c %c %d", &stato1, &input, &output, &testina, &stato2); 
    }
    /* --- STATI DI ACCETTAZIONE --- */

    getline_res = getline(&str, &str_len, stdin);     
    sscanf(str, "%d", &statoacc);
    while(strcmp(str, "max\n")){
        stati[statoacc].flagacc = 1;
        getline(&str, &str_len, stdin);     
        sscanf(str, "%d", &statoacc);
    }


    /* --- SALVATAGGIO MAX PASSI ESECUZIONE --- */

    while(strcmp(str, "run\n")){
        getline(&str, &str_len, stdin);     
        sscanf(str, "%ld", &maxcomp);
    }

    res = 0;
    dimcheck = 0;
    cont = 0;
    getline_res = getline(&str, &str_len, stdin);
    for(i = 0, fnd = 0; i < str_len && !fnd; i++){
        if(str[i] == '\n' || str[i] == '\r' || str[i] == '\0'){
            fnd = 1;
        }
    }
    if(fnd){
        for(i = i-1; i < str_len; i++){
            str[i] = BLANK;
        }
    }
    fnd = 0;

    ltape_len = 2;
    strleft = (char *)malloc(ltape_len * sizeof(char));
    for(i = 0; i < ltape_len; i++){
        strleft[i] = BLANK;
    }
    slen = getline_res;

    while(getline_res > 0){
 
        if(wait_list.head != NULL){
            queue.head = wait_list.head;
            wait_list.head = wait_list.head->next;

            if(wait_list.head == NULL){
                wait_list.tail = NULL;
            }
        }else{
            queue.head = (el_queue_t *)malloc(sizeof(el_queue_t));
        }
        queue.head->i_pos = 0;
        queue.head->stato = 0;
        queue.head->cont_mosse = cont;
        queue.head->line_len = slen;
        queue.head->line = (char *)malloc(queue.head->line_len * sizeof(char));
        memcpy(queue.head->line, str, queue.head->line_len);
        queue.head->tape_len = ltape_len;
        queue.head->ltape = (char *)malloc(queue.head->tape_len * sizeof(char));
        memcpy(queue.head->ltape, strleft, queue.head->tape_len);
        queue.head->next = NULL;
        queue.tail = queue.head;

        while(queue.head){
            
            i = queue.head->i_pos;
            stato1 = queue.head->stato;
            if(queue.head->cont_mosse > maxcomp){
                res = 2;
                goto liberalista;
            }else{
                if(stati[stato1].flagacc == 1){
                    res = 1;
                    goto liberalista;
                }    
            }
                
            if(res == 0){

                if(i >= 0){

                    if(i >= queue.head->line_len){
                        
                        dimcheck = queue.head->line_len;
                        queue.head->line_len = (int) ( 1.5 * queue.head->line_len);
                        queue.head->line = (char *)realloc(queue.head->line, queue.head->line_len * sizeof(char));
                        for(j = dimcheck; j < queue.head->line_len; j++){
                            queue.head->line[j] = '_';
                        }
                    }
                    for(j = 0, fnd = 0; j < dimcaratteri && !fnd; j++){
                        if(queue.head->line[i] == caratteri[j]){
                            fnd = 1;
                        }
                    }
                    j--;
                    if(j < stati[stato1].dimcinput){

                        if(fnd && stati[stato1].cinput[j]){

                            cont = queue.head->cont_mosse + 1;

                            if(stati[stato1].cinput[j]->next == NULL){
                                mem = 1;
                                queue.head->stato = stati[stato1].cinput[j]->stato2;                                
                                queue.head->line[queue.head->i_pos] = stati[stato1].cinput[j]->output;                               
                                if(stati[stato1].cinput[j]->testina == LEFT){
                                    queue.head->i_pos--;
                                }
                                if(stati[stato1].cinput[j]->testina == RIGHT){
                                    queue.head->i_pos++;
                                }                               
                                queue.head->cont_mosse = cont;

                                if(queue.head != queue.tail){
                                    queue.tail->next = queue.head;
                                    queue.tail = queue.head;
                                    queue.head = queue.head->next;
                                    queue.tail->next = NULL;
                                }
                            }else{

                                for(p = stati[stato1].cinput[j]; p; p = p->next){
                                    
                                    if(wait_list.head != NULL){
                                        nuovo = wait_list.head;
                                        wait_list.head = wait_list.head->next;

                                        if(wait_list.head == NULL){
                                            wait_list.tail = NULL;
                                        }
                                    }else{
                                        nuovo=(el_queue_t *)malloc(sizeof(el_queue_t));
                                    }
                                    nuovo->stato = p->stato2;
                                    nuovo->line_len = queue.head->line_len;
                                    nuovo->line = (char *)malloc(queue.head->line_len * sizeof(char));
                                    memcpy(nuovo->line, queue.head->line, queue.head->line_len);
                                    nuovo->line[queue.head->i_pos] = p->output;
                                    nuovo->i_pos = queue.head->i_pos;
                                    if(p->testina == LEFT){
                                        nuovo->i_pos--;
                                    }
                                    if(p->testina == RIGHT){
                                        nuovo->i_pos++;
                                    }
                                    nuovo->tape_len = queue.head->tape_len;
                                    nuovo->ltape = (char *)malloc(queue.head->tape_len * sizeof(char));
                                    memcpy(nuovo->ltape, queue.head->ltape, queue.head->tape_len);
                                    nuovo->cont_mosse = cont;
                                                                        
                                    nuovo->next = NULL;
                                    if(queue.head == NULL){
                                        queue.head = nuovo;
                                        queue.tail = queue.head;
                                    }else{
                                        queue.tail->next = nuovo;
                                        queue.tail = nuovo;                                       
                                    }

                                } 
                            }
                            
                        }else{              
                            goto libera;
                        }
                    }else{             
                        goto libera;
                    }      
                    
                }else{
                    if(abs(i) >= queue.head->tape_len){
                        dimcheck = queue.head->tape_len;
                        queue.head->tape_len = queue.head->tape_len * 2;
                        queue.head->ltape = (char *)realloc(queue.head->ltape, queue.head->tape_len * sizeof(char));
                        for(j = dimcheck; j < queue.head->tape_len; j++){
                            queue.head->ltape[j] = '_';
                        }

                    }
                    for(j = 0, fnd = 0; j < dimcaratteri && !fnd; j++){
                        if(queue.head->ltape[abs(i) - 1] == caratteri[j]){
                            fnd = 1;
                        }
                    }
                    j--;
                    if(j < stati[stato1].dimcinput){

                        if(fnd && stati[stato1].cinput[j]){

                            cont = queue.head->cont_mosse + 1;
                         
                            if(stati[stato1].cinput[j]->next == NULL){
                                mem = 1;
                                queue.head->stato = stati[stato1].cinput[j]->stato2;                                
                                queue.head->ltape[abs(queue.head->i_pos) - 1] = stati[stato1].cinput[j]->output;                               
                                if(stati[stato1].cinput[j]->testina == LEFT){
                                    queue.head->i_pos--;
                                }
                                if(stati[stato1].cinput[j]->testina == RIGHT){
                                    queue.head->i_pos++;
                                }                               
                                queue.head->cont_mosse = cont;
                                if(queue.head != queue.tail){
                                    queue.tail->next = queue.head;
                                    queue.tail = queue.head;
                                    queue.head = queue.head->next;
                                    queue.tail->next = NULL;
                                }
                            }else{

                                for(p = stati[stato1].cinput[j]; p; p = p->next){

                                    if(wait_list.head != NULL){
                                        nuovo = wait_list.head;
                                        wait_list.head = wait_list.head->next;

                                        if(wait_list.head == NULL){
                                            wait_list.tail = NULL;
                                        }
                                    }else{
                                        nuovo=(el_queue_t *)malloc(sizeof(el_queue_t));
                                    }
                                    
                                    nuovo->stato = p->stato2;
                                    nuovo->line_len = queue.head->line_len;
                                    nuovo->line = (char *)malloc(queue.head->line_len * sizeof(char));
                                    memcpy(nuovo->line, queue.head->line, queue.head->line_len);
                                    nuovo->tape_len = queue.head->tape_len;
                                    nuovo->ltape = (char *)malloc(queue.head->tape_len * sizeof(char));
                                    memcpy(nuovo->ltape, queue.head->ltape, queue.head->tape_len);
                                    nuovo->i_pos = queue.head->i_pos;
                                    if(p->testina == LEFT){
                                        nuovo->i_pos--;
                                    }
                                    if(p->testina == RIGHT){
                                        nuovo->i_pos++;
                                    }
                                    nuovo->ltape[abs(queue.head->i_pos) - 1] = p->output;
                                    nuovo->cont_mosse = cont;
                                    nuovo->next = NULL;
                                    if(queue.head == NULL){
                                        queue.head = nuovo;
                                        queue.tail = queue.head;
                                    }else{
                                        queue.tail->next = nuovo;
                                        queue.tail = nuovo;                                       
                                    }
                                }                       
                            }

                            
                        }else{
                            goto libera;
                        }
                    }else{
                        goto libera;
                    }

                }    
            } 

            if(mem == 0){
                libera:
                free(queue.head->line);
                free(queue.head->ltape);
                tmp = queue.head;
                queue.head = queue.head->next;
                if(wait_list.head == NULL){
                    wait_list.head = tmp;
                    wait_list.tail = wait_list.head;
                }else{
                    wait_list.tail->next = tmp;
                    wait_list.tail = tmp;
                }
                wait_list.tail->next = NULL;
            }
            mem = 0;
        } /
             
            
        liberalista:
        if(wait_list.head == NULL){
            wait_list.head = queue.head;
            wait_list.tail = queue.tail;
        }else{
            wait_list.tail->next = queue.head;
            wait_list.tail = queue.tail;
        }
        wait_list.tail->next = NULL;

        tmp = queue.head;
        while(queue.head){
            queue.head = queue.head->next;
            free(tmp->line);
            free(tmp->ltape);
            tmp = queue.head;
        }
        queue.tail = queue.head;
       

        if(res == 2){
            printf("U\n");
        }else{
            printf("%d\n", res);
        }

        getline_res = getline(&str, &str_len, stdin);
        for(i = 0, fnd = 0; i < str_len && !fnd; i++){
            if(str[i] == '\n' || str[i] == '\r' || str[i] == '\0'){
                fnd = 1;
            }
        }
        if(fnd){
            for(i = i-1; i < str_len; i++){
                str[i] = BLANK;
            }
        }
        


        free(strleft);
        ltape_len = 2;
        strleft = (char *)malloc(ltape_len * sizeof(char));
        for(i = 0; i < ltape_len; i++){
            strleft[i] = BLANK;
        }
        
        cont = 0;
        res = 0;
        dimcheck = 0;
        slen = getline_res;

    } 
    
    free(stati);
    return 0;
}



