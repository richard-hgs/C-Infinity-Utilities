#pragma once

#ifdef INFINITYGUI_EXPORTS
	#define INFINITY_GUI_API __declspec(dllexport)
#else
	#define INFINITY_GUI_API __declspec(dllimport)
#endif

extern "C++" class INFINITY_GUI_API EditText : public View {
	private:
		HWND	  hWnd;		                         			// JANELA EM QUE SE ENCONTRA O EditText
		HWND	  hWndEdit;										// INSTANCIA DO EDITOR DE TEXTO
	public:
		/**
			* @Override(View.h)
			* QUANDO A JANELA FOR CRIADA, CHAMAR ESSE M�TODO (OBRIGAT�RIO)
			*/
		void onCreate()																					const;
		/**
			* QUANDO A JANELA RECEBER UM COMANDO
			* @param hWnd		JANELA DE ONDE O COMANDO VEIO
			* @param message	MENSAGEM FORNECIDA PELO SISTEMA, POSSUI INFORMACAO RELACIONADA AO TIPO DE INTERA��O
			*					REALIZADA NA JANELA SEJA PELO USU�RIO OU SEJA PELA APLICA��O
			*					Ex: Movimentar mouse, digitar, clicks, digitacao em um campo
			* @param wParam	INFORMA��ES ADICIONAIS SOBRE MENSAGEM. O CONTE�DO DESTE PAR�METRO DEPENDE DO VALOR DO PAR�METRO uMsg.
			* @param lParam	INFORMA��ES ADICIONAIS SOBRE MENSAGEM. O CONTE�DO DESTE PAR�METRO DEPENDE DO VALOR DO PAR�METRO uMsg.
			*/
		void onCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)							const;
		/**
			* @Override(View.h)
			* QUANDO A JANELA FOR CALCULADA, CHAMAR ESSE M�TODO (OBRIGAT�RIO)
			* @param totWidth			LARGURA TOTAL DO LAYOUT PAI DESSA VIEW
			* @param totHeight			ALTURA TOTAL DO LAYOUT PAI DESSA VIEW
			* @param occupiedWidth		LARGURA TOTAL QUE J� SE ENCONTRA OCUPADA NO LAYOUT PAI
			* @param occupiedHeight	ALTURA TOTAL QUE J� SE ENCONTRA OCUPADA NO LAYOUT PAI
			*/
		void onMeasure(int totWidth, int totHeight, int occupiedWidth, int occupiedHeight)				const;
		/**
			* @Override(View.h)
			* QUANDO A JANELA FOR DESENHADA, CHAMAR ESSE M�TODO (OBRIGAT�RIO)
			* @param hdc				VARI�VEL DE PINTURA DA JANELA
			* @param thunk				VARI�VEL QUE EXECUTA A FUN��O ABSTRATA {callback_arg} ANTES DO DESENHO SER FEITO NO {hdc}
			* @param callback_arg		VAARI�VEL QUE � A FUN��O ABSTRATA A SER EXECUTADA ANTES DO DESENHO SER FEITO NO {hdc}
			*/
		void onPaint(HDC hdc, void(*thunk)(void*), void* callback_arg)									const;
		/**
			* @Override(View.h)
			* QUANDO A JANELA FOR DESTRUIDA, CHAMAR ESSE M�TODO (OBRIGAT�RIO)
			*/
		void onDestroy()																				const;

		// CONSTRUTOR 1 PADRAO
		EditText(void);
		// CONSTRUTOR 2 
		EditText(HWND hWnd);
};