//
// Created by diogo on 14/11/2019.
//

#ifndef PROJETOIAPG_IAPG_H
#define PROJETOIAPG_IAPG_H

int mainProjeto();
void menu();

void menuCliente();
void InserirCliente();
void EditarCliente();
void RemoverCliente();
void ListaCliente();
void ClienteParaFicheiro();
void ClienteDoFicheiro();

void menuDestino();
void InserirDestino();
void EditarDestino();
void RemoverDestino();
void ListaDestinos();
void DestinoParaFicheiro();
void DestinoDoFicheiro();

void menuAlojamento();
void InserirAlojamento();
void EditarAlojamento();
void RemoverAlojamento();
void ListaAlojamento();
void AlojamentoParaFicheiro();
void AlojamentoDoFicheiro();

void menuCategorias();
void InserirCategorias();
void EditarCategorias();
void RemoverCategorias();
void ListarCategorias();

void menuProcurar();
void PesquisarNome();
void PesquisarCategoria();
void PesquisarPreco();
void PesquisarCaracteristicasAlojamentos();
void PesquisarClassificacaoAlojamento();
void PesquisarPais();
void PesquisarCidade();

void menuViagens();
void listarViagem();
void listarTodasViagens();
void RemoverViagem();
void ViagensParaFicheiro();
void ViagensDoFicheiro();

#endif //PROJETOIAPG_IAPG_H
