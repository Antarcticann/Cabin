/*
 *  _______     ________    ________    ________    __
 * |   __  \   |__    __|  |   _____|  |   _____|  |  |
 * |  |  |  |     |  |     |  |        |  |_____   |  |
 * |  |  |  |     |  |     |  |        |   _____|  |__|
 * |  |__|  |   __|  |__   |  |_____   |  |_____    __
 * |_______/   |________|  |________|  |________|  |__|
 *
 * Dice! QQ Dice Robot for TRPG
 * Copyright (C) 2018-2019 w4123溯洄
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
 * 版本信息
 * 请勿修改Dice_Build, Dice_Ver_Without_Build，DiceRequestHeader以及Dice_Ver常量
 * 请修改Dice_Short_Ver或Dice_Full_Ver常量以达到版本自定义
 */
const unsigned short Dice_Build = 509;
const std::string Dice_Ver_Without_Build = "2.3.6";
const std::string DiceRequestHeader = "Dice/" + Dice_Ver_Without_Build;
const std::string Dice_Ver = Dice_Ver_Without_Build + "(" + std::to_string(Dice_Build) + ")";
const std::string Dice_Short_Ver = "Dice! by 溯洄 Version " + Dice_Ver;
const std::string Dice_Full_Ver = Dice_Short_Ver + " [MSVC " + std::to_string(_MSC_FULL_VER) + " " + __DATE__ + " " + __TIME__ + "]";

std::map<std::string, std::string> GlobalMsg
{
	{"strNameNumTooBig", "太多啦,你这是要给一个足球队起名么?请输入1-10之间的数字!"},
	{"strNameNumCannotBeZero", "???我起好啦,但是你看不见~请输入1-10之间的数字!"},
	{"strSetInvalid", "无效的默认骰!请输入1-99999之间的数字!"},
	{"strSetTooBig", "默认骰过大!请输入1-99999之间的数字!"},
	{"strSetCannotBeZero", "默认骰不能为零!请输入1-99999之间的数字!"},
	{"strCharacterCannotBeZero", "做好啦!诶?你看不到么?那请输入1-10之间的数字!"},
	{"strSetInvalid", "无效的默认骰!请输入1-99999之间的数字!"},
	{"strSetTooBig", "默认骰过大!请输入1-99999之间的数字!"},
	{"strSetCannotBeZero", "默认骰不能为零!请输入1-99999之间的数字!"},
	{"strCharacterCannotBeZero", "做好啦!诶?你看不到么?那请输入1-10之间的数字!"},
	{"strCharacterTooBig", "好多人，我脸盲症犯了!请输入1-10之间的数字!"},
	{"strCharacterInvalid", "你想说什么?请输入1-10之间的数字!"},
	{"strSCInvalid", "这种事还要我教你嘛?SC表达式格式为成功扣San/失败扣San,如1/1d6!"},
	{"strSanInvalid", "请您好好评估一下自己的精神状态然后输入1-99范围内的整数San值!"},
	{"strEnValInvalid", "技能值或属性输入不正确,请输入1-99范围内的整数!"},
	{"strGroupIDInvalid", "查无此群!请查证后再拨!"},
	{"strSendErr", "消息发送失败!是邮件丢了么?"},
	{"strDisabledErr", "不让咱说话还想让咱干活?(命令无法执行:青木莲已在此群中被关闭!)"},
	{"strMEDisabledErr", "已禁用.me命令!过家家禁止x"},
	{"strHELPDisabledErr", "已禁用.help命令!你们已经是大孩子啦,该学会自己百度了"},
	{"strNameDelErr", "我刚刚删掉了一个原本就不存在的名字诶！（没有设置名称,无法删除!）"},
	{"strValueErr", "这个我办不到啊!（掷骰表达式输入错误!）"},
	{"strInputErr", "你在为难我嘛?（命令或掷骰表达式输入错误!）"},
	{"strUnknownErr", "诶，刚才发生了什么？（未知错误!）"},
	{"strUnableToGetErrorMsg", "你问我我也不知道啊!(无法获取错误信息!)"},
	{"strDiceTooBigErr", "这么多骰子?你等会，我去库房取点冰多削几个......"},
	{"strRequestRetCodeErr", "一定是我的打开方式不对!（访问服务器时出现错误! HTTP状态码: {0}）"},
	{"strRequestNoResponse", "谁把网线拔了!?（服务器未返回任何信息"},
	{"strTypeTooBigErr", "这个球一开始转就根本停不下来诶（骰子面数过多!)"},
	{"strZeroTypeErr", "鬼知道我手上拿着个什么东西......（骰子面数为0!）"},
	{"strAddDiceValErr", "你这样要让我扔骰子扔到什么时候嘛~(请输入正确的加骰参数:5-10之内的整数)"},
	{"strZeroDiceErr", "骰子融化了!"},
	{"strRollTimeExceeded", "我会过劳死的!(掷骰轮数超过了最大轮数限制!）"},
	{"strRollTimeErr", "你在耍我嘛?(掷骰轮数异常!)"},
	{"strWelcomeMsgClearNotice", "看板已经擦干净啦(已清除本群的入群欢迎词)"},
	{"strWelcomeMsgClearErr", "那个...我们好像还没攒够钱买看板(错误:没有设置入群欢迎词，清除失败)"},
	{"strWelcomeMsgUpdateNotice", "新的看板写好啦(已更新本群的入群欢迎词)"},
	{"strPermissionDeniedErr", "你算哪根葱?（此操作需要群主或管理员权限）"},
	{"strNameTooLongErr", "名字太长，客户档案填不下啦(最多为50英文字符)"},
	{"strUnknownPropErr", "这是什么?客户档案上没有诶（属性不存在）"},
	{"strEmptyWWDiceErr", "格式错误:正确格式为.w(w)XaY!其中X≥1, 5≤Y≤10"},
	{"strPropErr", "请认真的，认真的，然后认真的输入你的属性哦~"},
	{"strSetPropSuccess", "新的用户信息已归档"},
	{"strPropCleared", "已按要求销毁用户档案!"},
	{"strRuleErr", "规则数据获取失败,具体信息:\n"},
	{"strRulesFailedErr", "电波断了!（请求失败,无法连接数据库）"},
	{"strPropDeleted", "已按要求销毁客户档案!"},
	{"strPropNotFound", "这是什么?客户档案上没有诶（属性不存在）"},
	{"strRuleNotFound", "未找到对应的规则信息"},
	{"strProp", "依据客户档案的记录,{0}的{1}属性值为{2}"},
	{"strStErr", "格式错误:请参考帮助文档获取.st命令的使用方法"},
	{"strRulesFormatErr", "格式错误:正确格式为.rules[规则名称:]规则条目 如.rules COC7:力量"},
	{"strJrrp", "根据{0}今天的运势,安排{0}前往{1}号雅座!"},
	{"strJrrpErr", "JRRP获取失败! 错误信息: \n{0}"},
	{"strHlpMsg" , Dice_Short_Ver + "\n" +
	R"(请使用!dismiss [机器人QQ号]命令让机器人自动退群或讨论组！
跑团记录着色器: https://logpainter.kokona.tech
<通用命令>
.r [掷骰表达式*] [原因]			普通掷骰
.rs	[掷骰表达式*] [原因]			简化输出
.w/ww XaY						骰池
.set [1-99999之间的整数]			设置默认骰
.sc SC表达式** [San值]			自动Sancheck
.en [技能名] [技能值]			增强检定/幕间成长
.coc7/6 [个数]					COC7/6人物作成
.dnd [个数]					DND人物作成
.coc7/6d					详细版COC7/6人物作成
.ti/li					疯狂发作-临时/总结症状
.st [del/clr/show] [属性名] [属性值]		人物卡导入
.rc/ra [技能名] [技能值]		技能检定(规则书/房规)
.jrrp [on/off]				今日人品检定
.name [cn/jp/en] [个数]			生成随机名称
.rules [规则名称:]规则条目		规则查询
.help						显示帮助
<仅限群/多人聊天>
.ri [加值] [昵称]			DnD先攻掷骰
.init [clr]					DnD先攻查看/清空
.nn [名称]					设置/删除昵称
.nnn [cn/jp/en]				随机设置昵称
.rh [掷骰表达式*] [原因]			暗骰,结果私聊发送
.bot [on/off] [机器人QQ号]		机器人开启或关闭
.ob [exit/list/clr/on/off]			旁观模式
.me on/off/动作				以第三方视角做出动作
.welcome 欢迎消息				群欢迎提示
.ct                         让青木莲随意为你调一杯酒
<仅限私聊>
.me 群号 动作				以第三方视角做出动作
*COC7惩罚骰为P+个数,奖励骰为B+个数
 支持使用K来取较大的几个骰子
 支持使用 个数#表达式 进行多轮掷骰
**SC表达式为 成功扣San/失败扣San,如:1/1d6
插件交流/bug反馈/查看源代码请加QQ群941980833或624807593(已满))"}
};