#ifndef TABELA_H
#define TABELA_H

#include "cpu_estado.h"
#include "mem.h"

typedef struct processo_l processo_l;
typedef struct tabela_t tabela_t ;

tabela_t* tabela_cria();
void tabela_destroi(tabela_t* self);
void processo_cadastra(tabela_t* self, cpu_estado_t* cpu_estado, mem_t* mem, int pid,
                        int proc_estado, int motiv_block);
void proc_destroi(processo_l* self);

#endif // TABELA_H