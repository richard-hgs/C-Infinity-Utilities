#include "pch.h"

#include "View.h"
#include "EditText.h"

// DEBUG
#include <string>
#include "Log.h"
//#include "StringHelper.h"

/**
 * @Override(View.h)
 * QUANDO A JANELA FOR CRIADA, CHAMAR ESSE M�TODO (OBRIGAT�RIO)
 */
void EditText::onCreate() const {

}

/**
 * QUANDO A JANELA RECEBER UM COMANDO
 * @param hWnd		JANELA DE ONDE O COMANDO VEIO
 * @param message	MENSAGEM FORNECIDA PELO SISTEMA, POSSUI INFORMACAO RELACIONADA AO TIPO DE INTERA��O
 *					REALIZADA NA JANELA SEJA PELO USU�RIO OU SEJA PELA APLICA��O
 *					Ex: Movimentar mouse, digitar, clicks, digitacao em um campo
 * @param wParam	INFORMA��ES ADICIONAIS SOBRE MENSAGEM. O CONTE�DO DESTE PAR�METRO DEPENDE DO VALOR DO PAR�METRO uMsg.
 * @param lParam	INFORMA��ES ADICIONAIS SOBRE MENSAGEM. O CONTE�DO DESTE PAR�METRO DEPENDE DO VALOR DO PAR�METRO uMsg.
 */
void EditText::onCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)					const {

}

/**
 * @Override(View.h)
 * QUANDO A JANELA FOR CALCULADA, CHAMAR ESSE M�TODO (OBRIGAT�RIO)
 */
void EditText::onMeasure(int totWidth, int totHeight, int occupiedWidth, int occupiedHeight)	const {
    if (this->getHeight() == View::MATCH_PARENT) {
        this->setMeasuredHeight(totHeight - occupiedHeight);
	} else if (this->getHeight() < 0) {
		// WRAP_CONTENT
        this->setMeasuredHeight(20);
	} else {
		// GREATER THAN 0
        this->setMeasuredHeight(this->getHeight());
	}

	if (this->getWidth() == View::MATCH_PARENT) {
        this->setMeasuredWidth(totWidth - occupiedWidth);
	} else if (this->getWidth() < 0) {
		// WRAP_CONTENT
        this->setMeasuredWidth(100);
	} else {
        // GREATER THAN 0
        this->setMeasuredWidth(this->getWidth());
    }
}

/**
 * @Override(View.h)
 * QUANDO A JANELA FOR DESENHADA, CHAMAR ESSE M�TODO (OBRIGAT�RIO)
 */
void EditText::onPaint(HDC hdc, void(*thunk)(void*), void* callback_arg)						const {
	// CHAMA CALLBACK BEFORE DRAW
	if (thunk != NULL && callback_arg != NULL) {
		thunk(callback_arg);
	}

    if (this->hWndEdit == nullptr) {
		const_cast<EditText*>(this)->hWndEdit = CreateWindowEx(
            WS_EX_CLIENTEDGE, 
            TEXT("Edit"), 
            NULL,
			WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            (this->getPosX() != -1 ? this->getPosX() : 0),
            (this->getPosY() != -1 ? this->getPosY() : 0), 
            this->getMeasuredWidth(),
			this->getMeasuredHeight(), 
            this->hWnd, 
            (HMENU)this->getId(), 
            NULL, 
            NULL
        );
    } else {
		SetWindowPos(
			this->hWndEdit,
            nullptr,
			(this->getPosX() != -1 ? this->getPosX() : 0),
			(this->getPosY() != -1 ? this->getPosY() : 0),
			this->getMeasuredWidth(),
			this->getMeasuredHeight(),
            SWP_NOZORDER | SWP_NOREPOSITION
		);
    }
}

/**
 * @Override(View.h)
 * QUANDO A JANELA FOR DESTRUIDA, CHAMAR ESSE M�TODO (OBRIGAT�RIO)
 */
void EditText::onDestroy()																		const {

}

/**
 * CONSTRUTOR 1 PADRAO
 */
EditText::EditText(void) : View() {
    this->hWnd = nullptr;
    this->hWndEdit = nullptr;
}

/**
 * CONSTRUTOR 2
 */
EditText::EditText(HWND hWnd) : View() {
    this->hWnd = hWnd;
    this->hWndEdit = nullptr;
}

/**
 * GETTERS AND SETTERS
 */
