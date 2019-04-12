﻿#include "CQLogger.h"
#include "GlobalVar.h"
#include <map>


std::map<std::string, std::string> CocktailList
{
	{ "1","Long Island Iced Tea（长岛冰茶） 20.61%Vol.\n浓烈的酒精味被更浓烈的红茶和可乐味覆盖。它不是茶，但尝起来也不像酒。\n微辣，浓郁，香甜" },
	{ "2","Blue Hawaii（蓝色夏威夷） 13.31%Vol.\n有时是蓝色，有时是绿色，但总归是Swimming Pool cocktail（游泳池鸡尾酒)的颜色\n酸，苦，清爽" },
	{ "3","B-52（B-52） 25.67%Vol.\n以同名乐的队的名字命名，不是那架飞机。最刺激的喝法是带着火喝下然后让火在嘴里灭掉，如此做的话后果自负。\n很冷，辣，很烫" },
	{ "4","Americano（美国佬） 21.50%Vol.\n最早被称为Milano-Torino，在美国禁酒令期间是到意大利的美国人最喜爱的鸡尾酒，因此得名\n微甜，苦，辣" },
	{ "5","Sea Breeze（海风） 8.42%Vol.\n被遗弃在荒岛海滩上的感觉，没有星期五。\n酸，微甜，咸" },
	{ "6","Pina Colada（椰林飘香） 8.00%Voi.\n至少有三个人想把自己的名字写在他的创作人一栏里\n甜美，治愈，温和" },
	{ "7","Tequila Sunrise（龙舌兰日出） 12.00%Vol.\n 一大杯红呼呼的朝霞\n厚重，浓烈，火辣，持久" },
	{ "8","Negroni（尼克罗尼） 27.67%Vol.\n强行把Americano（美国佬）中的苏打水替换成杜松子酒的产物\n苦，微甜，一点点酸" },
	{ "9","Bramble（树莓） 23.00%Vol.\n带着一股酸酸的甜腻腻的春天的味道\n很甜，微酸，奶油" },
	{ "10","Gin Fizz（琴费士） 21.18%Vol.\n就像摇晃可乐时发出的声音一样，滋——\n清凉，酸，发泡" },
	{ "11","Cuba Libre（自由古巴） 11.11%Vol.\n美国的可乐+古巴的朗姆酒=自由古巴，大概\n浓厚，解渴，微甜" },
	{ "12","Cosmopolitan（大都会） 19.00%Vol.\n“How cosmopolitan!”\n时尚，清爽，酸甜，靓丽" },
	{ "13","God Father（教父） 35.00%Vol.\n有人声称这款饮料是美国演员马龙白兰度最喜欢的鸡尾酒\n甜，芳香，浓厚" },
	{ "14","Mai-Tai（麦泰） 27.50%Vol.\n来自最接近天堂的地方。名意为：出神入化，不入凡尘。\n清凉，华丽，微甜" },
	{ "15","Manhattan（曼哈顿） 37.39%Vol.\n据说创造了这杯酒的人后来还创造了丘吉尔\n浓烈，较甜，很苦" },
	{ "16","Caipirinha（凯匹林纳） 37.74%Vol.\n适用于患有西班牙流感的患者，至少在人们决定去除原料中的大蒜和蜂蜜之前是这样的\n酸甜，微辣，微凉" },
	{ "17","Dry Martini（不甜马天尼） 36.43%Vol.\n不知道想要什么的时候来杯Martini肯定没错，如果想调出所有种类的Martini的话这座城市的杯子可能会不够用\n不甜，很苦，辛辣" },
	{ "18","Bacardi（百加得） 24.00%Vol.\n1936年4月28日，纽约最高法院裁定该饮料必须含有百加得朗姆酒?才能被称为百加得鸡尾酒\n丰厚，浓烈，刺激" },
	{ "19","Sex On The Beach（激情海岸） 14.29%Vol.\n在禁止说“sex”的时候也被称为“Fun On The Beach”或者“Peach On The Beach”\n微辣，酸甜，饱满" },
	{ "20","Tom Collins（汤姆柯林斯） 20.00%Vol.\n你见过汤姆柯林斯吗？\n酸，清爽，微甜" },
	{ "21","Margarita（玛格丽特） 31.43%Vol.\n眼泪的味道\n酸，甜，咸，清" },
	{ "22","Bloody Mary（血腥玛丽） 11.84%Vol.\n如果想要更血腥一些，可以再加点芥末\n很酸，很甜，很苦，很辣，很刺激" },
	{ "23","Old Fashioned（古典） 39.36%Vol.\n自认为古典的人一边喝着古典的杯子里盛着的古典的材料制成的古典鸡尾酒一边回忆着古典的事聊着古典的话题\n微甜，微苦，微凉，微醺" },
	{ "24","Whiskey Sour（威士忌酸酒） 15.0%Vol.\n味如其名，内含一点儿生蛋黄\n酸，酸，酸，烈" },
	{ "25","Screwdriver（渐入佳境） 13.33%Vol.\n请不要用自带的螺丝刀搅拌，全新的也不行\n酸甜，清爽，微苦" },
	{ "26","Kami-Kaze（神风） 20.00%Vol.\n听说喝下后会感觉犹如接受神力，希望您喝完别有什么奇怪的想法。顺便一提，这酒是美国人发明的。\n清爽，提神，刺激" },
	{ "27","mojito（莫吉托） 20.51%Vol.\n“我的Mojito在La Bodegutia，我的Daiquiri在El Floridita。”\n温和，清新，青涩，甜蜜" },
	{ "28","Black Russian（黑俄罗斯） 34.29%Vol.\n咖啡糖浆加在伏特加里，听说适合晚饭后喝，助眠\n较温和，较辣，黑" },
	{ "29","Daiquiri（得其利） 21.18%Vol.\n你总会有无数个关于想解除燥热的理由来让你喝下这么一杯Daiquiri\n浑浊，清甜，甘冽" },
	{ "30","Moscow Mule（莫斯科骡子） 10.53%Vol.\n你介意喝掉点铜么？\n很酸，凉，烈" },
	{ "31","Ieish Coffee（爱尔兰咖啡） 9.88%Vol.\n对猫舌头的顾客的劝退效果奇佳\n驱寒，甜，苦"},
	{ "32","Alexander（亚历山大） 21.33%Vol.\n像极了甜腻的爱情\n香甜，浓厚，顺滑"},
	{ "33","White Lady（白色丽人） 24.44%Vol.\n高贵冷艳，偶尔会给人一种自己配不上它的错觉\n清，苦，酸"},
	{ "34","Between The Sheets（床笫之间） 27.27Vol.\n寝前酒，常在卧室饮用。曾作为法国妓院的开胃酒。\n强烈，厚重，酸"},
	{ "35","Mimosa（含羞草） 6.50%Vol.\n世上有多少种水果，就有多少种含羞草\n开胃，发泡，清爽"},
	{ "36","Mint Julep（薄荷茱莉普） 35.82%Vol.\n症状：胃痛，频繁呕吐，吞咽困难\n处方：催吐药，开胃粉，Julep\n清爽，甜，刺激"},
	{ "37","Dark 'N' Stormy(月黑风高） 15.10%Vol.\nGosling Brothers已经注册了一个使用一个撇号（'N）的名称版本，而国际调酒师协会使用了两个撇号（'N'）\n原味，微辣，温和"},
	{ "38","Planter'S Punch（种植者潘趣） 12.24%Vol.\nDrink then you'll have that's not bad—\nAt least, so they say in Jamaica.\n酸甜，凉，微苦"},
	{ "39","SideCar（边车） 21.60%Vol.\n它一开始叫motorcycle attachment，指的是边三轮摩托的那个框\n酸甜，清爽，解乏"},
	{ "40","Singapore Sling（新加坡司令） 12.92%Vol.\n只要搭乘新加坡航空，不论任何舱等，都可以点免费的Singapore Sling。\n酸甜，温和，清爽"},
	{ "41","Grasshopper（绿色蚱蜢） 16.00Vol.\n我不确定这究竟是杯酒还是一杯甜点\n很甜，饼干，冰淇淋"},
	{ "42","God Mother（教母） 34.00Vol.\n把God Father的基酒换成了伏特加，然后起了个新的名字\n香醇，浓厚，温和"},
	{ "43","Bellini（贝里尼） 7.30%Vol.\n自从桃子不再是时令水果之后，不想吃桃子罐头的人也能在任何时候品尝到这款酒了\n甜，发泡，果味"},
	{ "44","French75（法兰西75） 18.5%Vol.\n喝下去的感觉就像被75mm野战炮击中了一样\n辛辣，酸，微甜"},
	{ "45","RustyNail(锈钉） 41.29%Vol.\n这款酒的命名过程从1937年持续到1963年\n芳醇，甜，凉"},
	{ "46","Barracuda（梭子鱼） 17.9%Vol.\n实在不知道为什么它会叫这个名字，名字仅供参考，请以实物为准\n发泡，芳香，开胃"},
	{ "47","Orgasm（高潮） 21.25%Vol.\n又叫做Shooter，你明白的\n甜，香，微凉"},
	{ "48","Russian Spring Punch（春日俄罗斯） 16.33%Vol.\n创作于伦敦，和俄罗斯唯一相关的地方大概就是用了伏特加作为基酒吧\n发泡，酸，甜"},
	{ "49","Aviation（飞行） 30.40%Vol.\n虽然紫罗兰利口酒恢复生产了，但是正宗的Avistion仍然比较稀有，不过它的味道一直褒贬不一\n烈，香，微凉"},
	{ "50","Carrot Juice（胡萝卜汁） 0.00%Vol.\n听说喝多了会全身变黄\n100.00%Carrot Juice"},/*mark*/
	{ "51","Brew Space-Mead(黄金蜂蜜酒） ？？？Vol.\n闪着诱人金黄色的液体，内含一点点魔法，仅供特殊顾客，交通工具自备\n芳香，辛辣，助眠"},/*mark*/
	{ "52","Gin Tonic(金汤力） 35.29%Vol.\n如果你一口气喝下1000mlGin Tonic的话，你体内的奎宁就能到达有效治疗浓度的下限\n清，凉，酸"},
	{ "53","Yellow Bird（黄鸟） 26.00%Vol.\nYou can fly away, in the sky away\nYou're more lucky than me~（青木莲小声地唱着歌）\n酸，甜，果香"},
	{ "54","Envy（嫉妒） 33.58%Vol.\n感到Envy，感到Bule\n蓝色，果香，清淡"},
	{ "55","Zombie（僵尸） 14.98%Vol.\n为了不让您醉成Zombie，我们建议您不要饮用超过两杯\n果香，平滑，后劲"},
	{ "56","French Connection（法国贩毒网） 34.00%Vol.\n以Gene Hackman主演的同名电影命名\n凉，浓烈，优雅）"},
	{ "57","Harvey Wallbanger（撞墙哈维） 14.52%Vol.\n据说冲浪手哈维在比赛失利后点了这种酒，然后因为喝得太醉疯狂撞墙...笑笑就好，别当真\n凉，酸，清爽"},
	{ "58","Clover Club（三叶草俱乐部） 23.68%Vol.\n虽然向酒品里面加入一些新奇的东西会有奇效，但是我不确定加入一整个鸡蛋的蛋清究竟是不是个好主意\n柔和，鲜艳，凉"},
	{ "59","Alien Brain Hemorrhage（脑溢血外星人） 25.15%Vol.\n恶...我见过有一些我们的客人带着类似的东西来过...但是那个肯定不能喝（青木莲小声嘟囔）\n鲜艳，甜，酸"},
	{ "60","Amaretto Sour（杏仁酸酒） 28.00%Vol.\n杏仁利口酒加上一堆料理用不完的调料制成的酒\n酸，酸，酸，凉"},
	{ "61","Twin Island Milk（双岛牛奶） 0.00%Vol.\n升华身心，强健骨骼，修复基因，提神醒脑，乳糖不耐受者请勿饮用\n完美，愉悦，无限"},/*mark*/
	{ "62","Tekeli（忒基里） 17.20%Vol.\n如果这杯酒开始对你说话，或者模仿你的样子，请不要担心，这是正常现象，但是我们不鼓励任何人尝试与其交流\n刺激，粘稠，浓厚"}/*mark*/
};