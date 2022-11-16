#include <stdio.h>
#include <stdalign.h>
#include "tabela_processos.h"
#include "cpu_estado.h"
#include "mem.h"

#define EXEC 0
#define PRONTO 1
#define BLOCK 2

struct processo_l {
    cpu_estado_t* cpu_estado;
    mem_t* mem;
    int pid;
    int proc_estado;
    int motivo_block;
};

struct tabela_t {
    processo_l** processos;
    int tam;
};

tabela_t* tabela_cria() {
    tabela_t* tabela = (tabela_t*) malloc(sizeof(tabela_t));
    tabela->tam = 0;
    tabela->processos = (processo_l**) malloc (100 * sizeof(processo_l*));
}

void tabela_destroi(tabela_t* self) {
    for(int i = 0; i < self->tam; i++) {
        proc_destroi(self->processos[i]);
    }
    free(self);
}

void processo_cadastra(tabela_t* self, cpu_estado_t* cpu_estado, mem_t* mem, int pid,
                        int proc_estado, int motiv_block)
{
    processo_l* proc = (processo_l*) malloc(sizeof(processo_l));
    cpue_copia(cpu_estado, proc->cpu_estado);
    proc->mem = mem;
    proc->proc_estado = proc_estado;
    proc->pid = pid;
    proc->motivo_block = motiv_block;
    self->processos[self->tam] = proc;
    self->tam++;
}

void proc_destroi(processo_l* self) {
    free(self);
}


