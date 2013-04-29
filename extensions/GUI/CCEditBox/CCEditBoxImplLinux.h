/****************************************************************************
 Copyright (c) 2010-2013 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef CCEDITBOXIMPLLINUX_H_
#define CCEDITBOXIMPLLINUX_H_

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

#include "ExtensionMacros.h"
#include "CCEditBoxImpl.h"

NS_CC_EXT_BEGIN

class	CCEditBoxImplLinux : public CCEditBoxImpl, public cocos2d::CCIMEDelegate {

		public:
		CCEditBoxImplLinux(CCEditBox* pEditText);
		~CCEditBoxImplLinux();

		bool initWithSize(const CCSize& size);
		void setFont(const char* pFontName, int fontSize);
		void setFontColor(const ccColor3B& color);
		void setPlaceholderFont(const char* pFontName, int fontSize);
		void setPlaceholderFontColor(const ccColor3B& color);
		void setInputMode(EditBoxInputMode inputMode);
		void setInputFlag(EditBoxInputFlag inputFlag);
		void setMaxLength(int maxLength);
		int getMaxLength();
		void setReturnType(KeyboardReturnType returnType);
		bool isEditing();

		void setText(const char* pText);
		const char* getText(void);
		void setPlaceHolder(const char* pText);
		void doAnimationWhenKeyboardMove(float duration, float distance);

		void openKeyboard();
		void closeKeyboard();

		void setPosition(const CCPoint& pos);
		void setVisible(bool visible);
		void setContentSize(const CCSize& size);
		void setAnchorPoint(const CCPoint& anchorPoint);
		void visit(void);
		void onEnter(void);

		void insertText(const char * text, int len);
	    void deleteBackward();
	    const char * getContentText();
	    bool canAttachWithIME() { return true; }
	    bool canDetachWithIME() { return true; }

	private:

		CCLabelTTF* m_pLabel;
		CCLabelTTF* m_pLabelPlaceHolder;
		EditBoxInputMode m_eEditBoxInputMode;
		EditBoxInputFlag m_eEditBoxInputFlag;
		KeyboardReturnType m_eKeyboardReturnType;

		std::string m_strText;
		std::string m_strPlaceHolder;

		ccColor3B m_colText;
		ccColor3B m_colPlaceHolder;

		int m_nMaxLength;
		CCSize m_EditSize;
	};

	NS_CC_EXT_END

#endif

#endif /* CCEDITBOXIMPLLINUX_H_ */

