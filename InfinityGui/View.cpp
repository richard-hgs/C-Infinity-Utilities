#include "pch.h"

#include "View.h"

///**
// * M�TODOS ABSTRATOS UTILIZADOS POR TODOS OS FILHOS(OBRIGAT�RIO)
// */
// /**
//  * QUANDO A JANELA FOR CRIADA
//  */
//void View::onCreate()																		const {
//}
//
///**
// * QUANDO A JANELA RECEBER UM COMANDO
// * @param hWnd		JANELA DE ONDE O COMANDO VEIO
// * @param message	MENSAGEM FORNECIDA PELO SISTEMA, POSSUI INFORMACAO RELACIONADA AO TIPO DE INTERA��O
// *					REALIZADA NA JANELA SEJA PELO USU�RIO OU SEJA PELA APLICA��O
// *					Ex: Movimentar mouse, digitar, clicks, digitacao em um campo
// * @param wParam	INFORMA��ES ADICIONAIS SOBRE MENSAGEM. O CONTE�DO DESTE PAR�METRO DEPENDE DO VALOR DO PAR�METRO uMsg.
// * @param lParam	INFORMA��ES ADICIONAIS SOBRE MENSAGEM. O CONTE�DO DESTE PAR�METRO DEPENDE DO VALOR DO PAR�METRO uMsg.
// */
//void View::onCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)				const {
//}
//
///**
// * QUANDO A JANELA FOR REDIMENSIONADA CALCULA AS DIMENS�ES DA VIEW
// * @param totWidth			LARGURA TOTAL DO LAYOUT PAI DESSA VIEW
// * @param totHeight			ALTURA TOTAL DO LAYOUT PAI DESSA VIEW
// * @param occupiedWidth		LARGURA TOTAL QUE J� SE ENCONTRA OCUPADA NO LAYOUT PAI
// * @param occupiedHeight	ALTURA TOTAL QUE J� SE ENCONTRA OCUPADA NO LAYOUT PAI
// */
//void View::onMeasure(int totWidth, int totHeight, int occupiedWidth, int occupiedHeight)	const {
//}
//
///**
// * QUANDO A JANELA FOR DESENHADA
// * @param hdc				VARI�VEL DE PINTURA DA JANELA
// * @param thunk				VARI�VEL QUE EXECUTA A FUN��O ABSTRATA {callback_arg} ANTES DO DESENHO SER FEITO NO {hdc}
// * @param callback_arg		VAARI�VEL QUE � A FUN��O ABSTRATA A SER EXECUTADA ANTES DO DESENHO SER FEITO NO {hdc}
// */
//void View::onPaint(HDC hdc, void(*thunk)(void*), void* callback_arg)						const {
//}
//
///**
// * QUANDO A JANELA FOR DESTRUIDA
// */
//void View::onDestroy()																	    const {
//}