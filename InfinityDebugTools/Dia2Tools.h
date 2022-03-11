#pragma once

#include <atlbase.h>					// BIBLIOTECA DE MODELOS ATIVOS
#include <dia2.h>						// BIBLIOTECA DE DEPURA��O DE ACESSO A INTERFACE SDK

class Dia2Tools {
	private:
		/**
		 * ARMAZENA CAMINHO DO ARQUIVO .pdb
		 */
		const char* szFilename;

		/**
		 * ARMAZENA A INSTANCIA DA BIBLIOTECA dia2.h
		 */
		CComPtr<IDiaDataSource> pSource;

		/**
		 * ARMAZENA RECURSOS INJETADOS dia2.h
		 */
		CComPtr<IDiaInjectedSource> piSource;

		/**
		 * ARMAZENA A SESSAO DA BIBLIOTECA dia2.h
		 */
		CComPtr<IDiaSession> pSession;

		/**
		 * ARMAZENA OS SIMBOLOS DA SESSAO dia2.h
		 */
		CComPtr<IDiaSymbol> pSymbol;

		/**
		 * ARMAZENA AS TABELAS DISPON�VEIS DA SESSAO dia2.h
		 */
		CComPtr<IDiaEnumTables> pTables;


		CComPtr<IDiaStackWalker> pStackWalker;

		/**
		 * EXIBE UM ERRO E FINALIZA A APLICA��O
		 * @msg		MENSAGEM DE ERRO A SER EXIBIDA
		 */
		void Fatal(const char* msg);

		/**
		 * EXIBE UM ERRO E N�O FINALIZA A APLICA��O
		 * @msg		MENSAGEM DE ERRO A SER EXIBIDA
		 */
		void Error(const char* msg);

		/**
		 * RECEBE A LISTA DE CONTRIBUI��ES DE SESSOES DO ARQUIVO .pdb
		 */
		IDiaEnumSectionContribs* GetEnumSectionContribs();

		/**
		 * EXIBE A LISTA DE CONTRIBUI��ES DE SESSOES DO ARQUIVO .pdb
		 */
		void ShowSectionContribs();

		/**
		 * EXIBE A CONTRIBUI��O DE SESSOES INFORMADA DO ARQUIVO .pdb
		 */
		void PrintSectionContrib(IDiaSectionContrib* pSecContrib, IDiaSession* pSession);

		/**
		 * EXIBE O RECURSO INJETADO
		 */
		void PrintInjectedSource();

		/**
		 * RECEBE A LISTA DE RECURSOS INJETADOS
		 */
		IDiaEnumInjectedSources* GetEnumInjectedSources();

		/**
		 * EXIBE TODOS OS RECURSOS INJETADOS
		 */
		void DumpAllInjectedSources();

		/**
		 * EXIBE A PROPRIEDADE DE ARMAZENAMENTO
		 */
		void PrintPropertyStorage(IDiaPropertyStorage* pPropertyStorage);

	public:
		/**
		 * CONSTRUTOR 1 PADRAO
		 */
		Dia2Tools(void);

		/**
		 * CONSTRUTOR 2
		 */
		Dia2Tools(const char* szFilename);

		/**
		 * LISTA TODAS AS TABELAS DE DADOS
		 */
		void listAllTablesItens();

		/**
		 * NAVEGA PELO STACK TRACE
		 */
		void stackTrace();

		IDiaEnumStackFrames* enumStackFrames();

		/**
		 * EXIBE AS INFORMACOES DO STACK FRAME INFORMADO
		 */
		void printStackFrame(IDiaStackFrame* pFrame);
};