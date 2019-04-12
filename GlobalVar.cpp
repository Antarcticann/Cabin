/*
 *  _______     ________    ________    ________    __
 * |   __  \   |__    __|  |   _____|  |   _____|  |  |
 * |  |  |  |     |  |     |  |        |  |_____   |  |
 * |  |  |  |     |  |     |  |        |   _____|  |__|
 * |  |__|  |   __|  |__   |  |_____   |  |_____    __
 * |_______/   |________|  |________|  |________|  |__|
 *
 * Dice! QQ Dice Robot for TRPG
 * Copyright (C) 2018-2019 w4123���
 *
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Affero General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this
 * program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "CQLogger.h"
#include "GlobalVar.h"
#include <map>

bool Enabled = false;

bool msgSendThreadRunning = false;

CQ::logger DiceLogger("Dice!");

/*
 * �汾��Ϣ
 * �����޸�Dice_Build, Dice_Ver_Without_Build��DiceRequestHeader�Լ�Dice_Ver����
 * ���޸�Dice_Short_Ver��Dice_Full_Ver�����Դﵽ�汾�Զ���
 */
const unsigned short Dice_Build = 509;
const std::string Dice_Ver_Without_Build = "2.3.6";
const std::string DiceRequestHeader = "Dice/" + Dice_Ver_Without_Build;
const std::string Dice_Ver = Dice_Ver_Without_Build + "(" + std::to_string(Dice_Build) + ")";
const std::string Dice_Short_Ver = "Dice! by ��� Version " + Dice_Ver;
const std::string Dice_Full_Ver = Dice_Short_Ver + " [MSVC " + std::to_string(_MSC_FULL_VER) + " " + __DATE__ + " " + __TIME__ + "]";

std::map<std::string, std::string> GlobalMsg
{
	{"strNameNumTooBig", "̫����,������Ҫ��һ�����������ô?������1-10֮�������!"},
	{"strNameNumCannotBeZero", "???�������,�����㿴����~������1-10֮�������!"},
	{"strSetInvalid", "��Ч��Ĭ����!������1-99999֮�������!"},
	{"strSetTooBig", "Ĭ��������!������1-99999֮�������!"},
	{"strSetCannotBeZero", "Ĭ��������Ϊ��!������1-99999֮�������!"},
	{"strCharacterCannotBeZero", "������!��?�㿴����ô?��������1-10֮�������!"},
	{"strSetInvalid", "��Ч��Ĭ����!������1-99999֮�������!"},
	{"strSetTooBig", "Ĭ��������!������1-99999֮�������!"},
	{"strSetCannotBeZero", "Ĭ��������Ϊ��!������1-99999֮�������!"},
	{"strCharacterCannotBeZero", "������!��?�㿴����ô?��������1-10֮�������!"},
	{"strCharacterTooBig", "�ö��ˣ�����ä֢����!������1-10֮�������!"},
	{"strCharacterInvalid", "����˵ʲô?������1-10֮�������!"},
	{"strSCInvalid", "�����»�Ҫ�ҽ�����?SC���ʽ��ʽΪ�ɹ���San/ʧ�ܿ�San,��1/1d6!"},
	{"strSanInvalid", "�����ú�����һ���Լ��ľ���״̬Ȼ������1-99��Χ�ڵ�����Sanֵ!"},
	{"strEnValInvalid", "����ֵ���������벻��ȷ,������1-99��Χ�ڵ�����!"},
	{"strGroupIDInvalid", "���޴�Ⱥ!���֤���ٲ�!"},
	{"strSendErr", "��Ϣ����ʧ��!���ʼ�����ô?"},
	{"strDisabledErr", "������˵���������۸ɻ�?(�����޷�ִ��:��ľ�����ڴ�Ⱥ�б��ر�!)"},
	{"strMEDisabledErr", "�ѽ���.me����!���Ҽҽ�ֹx"},
	{"strHELPDisabledErr", "�ѽ���.help����!�����Ѿ��Ǵ�����,��ѧ���Լ��ٶ���"},
	{"strNameDelErr", "�Ҹո�ɾ����һ��ԭ���Ͳ����ڵ�����������û����������,�޷�ɾ��!��"},
	{"strValueErr", "����Ұ첻����!���������ʽ�������!��"},
	{"strInputErr", "����Ϊ������?��������������ʽ�������!��"},
	{"strUnknownErr", "�����ղŷ�����ʲô����δ֪����!��"},
	{"strUnableToGetErrorMsg", "��������Ҳ��֪����!(�޷���ȡ������Ϣ!)"},
	{"strDiceTooBigErr", "��ô������?��Ȼᣬ��ȥ�ⷿȡ�����������......"},
	{"strRequestRetCodeErr", "һ�����ҵĴ򿪷�ʽ����!�����ʷ�����ʱ���ִ���! HTTP״̬��: {0}��"},
	{"strRequestNoResponse", "˭�����߰���!?��������δ�����κ���Ϣ"},
	{"strTypeTooBigErr", "�����һ��ʼת�͸���ͣ����������������������!)"},
	{"strZeroTypeErr", "��֪�����������Ÿ�ʲô����......����������Ϊ0!��"},
	{"strAddDiceValErr", "������Ҫ�����������ӵ�ʲôʱ����~(��������ȷ�ļ�������:5-10֮�ڵ�����)"},
	{"strZeroDiceErr", "�����ڻ���!"},
	{"strRollTimeExceeded", "�һ��������!(�������������������������!��"},
	{"strRollTimeErr", "����ˣ����?(���������쳣!)"},
	{"strWelcomeMsgClearNotice", "�����Ѿ����ɾ���(�������Ⱥ����Ⱥ��ӭ��)"},
	{"strWelcomeMsgClearErr", "�Ǹ�...���Ǻ���û�ܹ�Ǯ�򿴰�(����:û��������Ⱥ��ӭ�ʣ����ʧ��)"},
	{"strWelcomeMsgUpdateNotice", "�µĿ���д����(�Ѹ��±�Ⱥ����Ⱥ��ӭ��)"},
	{"strPermissionDeniedErr", "�����ĸ���?���˲�����ҪȺ�������ԱȨ�ޣ�"},
	{"strNameTooLongErr", "����̫�����ͻ����������(���Ϊ50Ӣ���ַ�)"},
	{"strUnknownPropErr", "����ʲô?�ͻ�������û���������Բ����ڣ�"},
	{"strEmptyWWDiceErr", "��ʽ����:��ȷ��ʽΪ.w(w)XaY!����X��1, 5��Y��10"},
	{"strPropErr", "������ģ�����ģ�Ȼ������������������Ŷ~"},
	{"strSetPropSuccess", "�µ��û���Ϣ�ѹ鵵"},
	{"strPropCleared", "�Ѱ�Ҫ�������û�����!"},
	{"strRuleErr", "�������ݻ�ȡʧ��,������Ϣ:\n"},
	{"strRulesFailedErr", "�粨����!������ʧ��,�޷��������ݿ⣩"},
	{"strPropDeleted", "�Ѱ�Ҫ�����ٿͻ�����!"},
	{"strPropNotFound", "����ʲô?�ͻ�������û���������Բ����ڣ�"},
	{"strRuleNotFound", "δ�ҵ���Ӧ�Ĺ�����Ϣ"},
	{"strProp", "���ݿͻ������ļ�¼,{0}��{1}����ֵΪ{2}"},
	{"strStErr", "��ʽ����:��ο������ĵ���ȡ.st�����ʹ�÷���"},
	{"strRulesFormatErr", "��ʽ����:��ȷ��ʽΪ.rules[��������:]������Ŀ ��.rules COC7:����"},
	{"strJrrp", "����{0}���������,����{0}ǰ��{1}������!"},
	{"strJrrpErr", "JRRP��ȡʧ��! ������Ϣ: \n{0}"},
	{"strHlpMsg" , Dice_Short_Ver + "\n" +
	R"(��ʹ��!dismiss [������QQ��]�����û������Զ���Ⱥ�������飡
���ż�¼��ɫ��: https://logpainter.kokona.tech
<ͨ������>
.r [�������ʽ*] [ԭ��]			��ͨ����
.rs	[�������ʽ*] [ԭ��]			�����
.w/ww XaY						����
.set [1-99999֮�������]			����Ĭ����
.sc SC���ʽ** [Sanֵ]			�Զ�Sancheck
.en [������] [����ֵ]			��ǿ�춨/Ļ��ɳ�
.coc7/6 [����]					COC7/6��������
.dnd [����]					DND��������
.coc7/6d					��ϸ��COC7/6��������
.ti/li					�����-��ʱ/�ܽ�֢״
.st [del/clr/show] [������] [����ֵ]		���￨����
.rc/ra [������] [����ֵ]		���ܼ춨(������/����)
.jrrp [on/off]				������Ʒ�춨
.name [cn/jp/en] [����]			�����������
.rules [��������:]������Ŀ		�����ѯ
.help						��ʾ����
<����Ⱥ/��������>
.ri [��ֵ] [�ǳ�]			DnD�ȹ�����
.init [clr]					DnD�ȹ��鿴/���
.nn [����]					����/ɾ���ǳ�
.nnn [cn/jp/en]				��������ǳ�
.rh [�������ʽ*] [ԭ��]			����,���˽�ķ���
.bot [on/off] [������QQ��]		�����˿�����ر�
.ob [exit/list/clr/on/off]			�Թ�ģʽ
.me on/off/����				�Ե������ӽ���������
.welcome ��ӭ��Ϣ				Ⱥ��ӭ��ʾ
.ct                         ����ľ������Ϊ���һ����
<����˽��>
.me Ⱥ�� ����				�Ե������ӽ���������
*COC7�ͷ���ΪP+����,������ΪB+����
 ֧��ʹ��K��ȡ�ϴ�ļ�������
 ֧��ʹ�� ����#���ʽ ���ж�������
**SC���ʽΪ �ɹ���San/ʧ�ܿ�San,��:1/1d6
�������/bug����/�鿴Դ�������QQȺ941980833��624807593(����))"}
};