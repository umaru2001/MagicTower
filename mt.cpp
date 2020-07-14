#include"mt.h"
#include"variables.h"


char input_char;
FLOOR Tower[TOTAL_FLOOR];
int result = 0;
character Braver(900, 10, 10, 0, 0, 6, 0, 0, 1, 1, 1, 1, 1, "a", "O");
//hp,at,df,gold,exp,(x,y),floor,face,lv,ykey,bkey,rkey,"name","img";
monster m_array[1]=
{ monster(50, 18, 2, 1000, 1, 1, "slm", "H") //hp,at,df,gold,exp,id,"name","img";
};

void init_tower()
{
    FLOOR tmpfloor_1 = {
            10, 0, 51, 51, 51, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
            0, 51, 0, 1, 0, 1, 0, 0, 0, 1, 0,
            1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0,
            0, 0, 0, 1, 0, 0, 51, 51, 51, 1, 0,
            0, 51, 0, 1, 0, 1, 1, 1, 1, 1, 0,
            1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            34, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1,
            35, 37, 0, 1, 0, 0, 0, 1, 0, 51, 0,
            36, 38, 39, 1, 0, 0, 0, 1, 0, 0, 0,
    };
    memcpy(Tower[0], tmpfloor_1, sizeof(int) * X * Y);

    FLOOR tmpfloor_2 = {
        11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 0, 51, 0, 51, 0, 1, 1,
        0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
        0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 0, 0, 1, 0, 0, 0, 1, 31, 31,
        0, 1, 44, 0, 0, 0, 0, 0, 31, 31, 31,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 0, 0, 1, 0, 0, 0, 1, 21, 21,
        14, 1, 42, 0, 0, 0, 0, 0, 0, 21, 21,
    };
    memcpy(Tower[1], tmpfloor_2, sizeof(int) * X * Y);
}

GLOBAL_VARS vars(0, 0);

int calc_damage(int monster_id)
{
    //计算伤害值。
    if (Braver.at <= m_array[monster_id].df)
    {
        if (m_array[monster_id].at > Braver.df)
            return -1;
        else
            return -2;
    }
    else {
        if (m_array[monster_id].at > Braver.df) {
            int atk_times = (m_array[monster_id].hp - 1) / (Braver.at - m_array[monster_id].df);
            return atk_times * (m_array[monster_id].at - Braver.df);
        }
        else {
            return 0;
        }
    }
}

int handle_keypress(int key_no)
{

    // 返回操作状态。0为可以操作，1为对话模式（暂未实现），2为game_over, 3为开门, 4为上下楼, 5为战斗, 6为提示获得物品信息, 7为开启商店处理
    int target_pos;
    int old_data = -1;
    if (key_no == 0) { //向左
        Braver.face = 1; //0/1/2/3分别代表下左右上
        if (Braver.pos_x == 0)
            return 0;
        else
            target_pos = Braver.pos_y * X + (Braver.pos_x - 1);
    }
    else if (key_no == 1) { //向上
        Braver.face = 3;
        if (Braver.pos_y == 0)
            return 0;
        else
            target_pos = (Braver.pos_y - 1) * X + Braver.pos_x;
    }
    else if (key_no == 2) { //向右
        Braver.face = 2;
        if (Braver.pos_x == X - 1)
            return 0;
        else
            target_pos = Braver.pos_y * X + (Braver.pos_x + 1);
    }
    else if (key_no == 3) { //向下
        Braver.face = 0;
        if (Braver.pos_y == Y - 1)
            return 0;
        else
            target_pos = (Braver.pos_y + 1) * X + Braver.pos_x;
    }
    else {
        return 0;
    }
    old_data = Tower[Braver.floor][target_pos];
    if (Tower[Braver.floor][target_pos] == 0) {
        //平地 直接走过去
        Braver.pos_x = target_pos % X;
        Braver.pos_y = target_pos / X;
        return 0;
    }
    else if ((Tower[Braver.floor][target_pos] >= 1 && Tower[Braver.floor][target_pos] <= 9) || Tower[Braver.floor][target_pos] == 41 || Tower[Braver.floor][target_pos] == 43) {
        //撞墙 位置不变化
        return 0;
    }
    else if (Tower[Braver.floor][target_pos] == 10) {
        //上楼
        if (Braver.floor != TOTAL_FLOOR - 1) {
            Braver.floor += 1;
            int target_pos_upper = 0;
            for (int _it = 0; _it <= X * Y - 1; _it++) {
                if (Tower[Braver.floor][_it] == 11) {
                    target_pos_upper = _it;
                    break;
                }
            }
            Braver.pos_x = target_pos_upper % X;
            Braver.pos_y = target_pos_upper / X;
        }
        return 4;
    }
    else if (Tower[Braver.floor][target_pos] == 11) {
        //下楼
        if (Braver.floor != 0) {
            Braver.floor -= 1;
            int target_pos_lower = 0;
            for (int _it = 0; _it <= X * Y - 1; _it++) {
                if (Tower[Braver.floor][_it] == 10) {
                    target_pos_lower = _it;
                    break;
                }
            }
            Braver.pos_x = target_pos_lower % X;
            Braver.pos_y = target_pos_lower / X;

        }
        return 4;
    }
    else if (Tower[Braver.floor][target_pos] == 12) {
        //触发结局一：离开。直接Game Over
        vars.end_no = 1;
        return 1;
    }
    else if (Tower[Braver.floor][target_pos] == 14) {
        vars.hint_msg = "3层之后的内容，还未制作完成。";
        return 1;
    }
    
    else if (Tower[Braver.floor][target_pos] == 21) {
        //黄门
        if (Braver.ykey >= 1) {
            Braver.ykey -= 1;
            Tower[Braver.floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 22) {
        //蓝门
        if (Braver.bkey >= 1) {
            Braver.bkey -= 1;
            Tower[Braver.floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 23) {
        //红门
        if (Braver.rkey >= 1) {
            Braver.rkey -= 1;
            Tower[Braver.floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 25) {
        //铁门
        Tower[Braver.floor][target_pos] = 0;
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 26) {
        //暗墙，这里可能会考虑用任意门实现，暂时保留
        Tower[Braver.floor][target_pos] = 0;
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 31) {
        //黄钥匙
        Tower[Braver.floor][target_pos] = 0;
        Braver.ykey += 1;
        vars.gain_item_msg = "获得了一把黄钥匙";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 32) {
        //蓝钥匙
        Tower[Braver.floor][target_pos] = 0;
        Braver.bkey += 1;
        vars.gain_item_msg = "获得了一把蓝钥匙";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 33) {
        //红钥匙
        Tower[Braver.floor][target_pos] = 0;
        Braver.rkey += 1;
        vars.gain_item_msg = "获得了一把红钥匙";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 34) {
        //小血瓶 序号：34
        Tower[Braver.floor][target_pos] = 0;
        Braver.hp += 50;
        vars.gain_item_msg = "获得了小血瓶 生命值增加50";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 35) {
        //大血瓶 序号：35
        Tower[Braver.floor][target_pos] = 0;
        Braver.hp += 200;
        vars.gain_item_msg = "获得了大血瓶 生命值增加200";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 36) {
        //红宝石 序号：36
        Tower[Braver.floor][target_pos] = 0;
        Braver.at += 1;
        vars.gain_item_msg = "获得了红宝石 攻击力增加1点";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 37) {
        //蓝宝石 序号：37
        Tower[Braver.floor][target_pos] = 0;
        Braver.df += 1;
        vars.gain_item_msg = "获得了蓝宝石 防御力增加1点";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 38) {
        //铁剑 序号：38
        Tower[Braver.floor][target_pos] = 0;
        Braver.at += 10;
        vars.gain_item_msg = "获得了铁剑 攻击力增加10点";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 39) {
        //铁盾 序号：39
        Tower[Braver.floor][target_pos] = 0;
        Braver.df += 10;
        vars.gain_item_msg = "获得了铁盾 防御力增加10点";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 42) {
        //商店处理1
        vars.store_no = 0;
        return 7;
    }
    else if (Tower[Braver.floor][target_pos] == 43) {
        //商店处理2
        vars.store_no = 1;
        return 7;
    }
    else if (Tower[Braver.floor][target_pos] == 44) {
        //商店处理3
        vars.store_no = 2;
        return 7;
    }
    else if (Tower[Braver.floor][target_pos] == 45) {
        //商店处理4
        vars.store_no = 3;
        return 7;
    }
    else if (Tower[Braver.floor][target_pos] >= 51) {
        //怪物
        int monster_id = Tower[Braver.floor][target_pos] - 51;
        int damage = calc_damage(monster_id);
        if (damage == -2) {
            //在打不过时，不进行任何处理
            vars.hint_msg = "你还不能打败他";
            return 0;
        }
        else if (damage == -1 || damage >= Braver.hp) {
            //在打不过时，不进行任何处理
            vars.hint_msg = "你还不能打败他";
            return 0;
        }
        else {
            Braver.hp -= damage;
            Braver.gold += m_array[monster_id].gold;
            Braver.exp += m_array[monster_id].exp;
            Tower[Braver.floor][target_pos] = 0;
            return 5;
        }
    }
    return 0;
}
char choice = '0';
void handle_store()// 商店处理（金币商店1:编号为0;经验商店1:编号为1;金币商店2:编号为2;经验商店2:编号为3;)
{
    int store_price_0 = 20;//第一个商店从20golds开始涨价
    int store_price_2 = 50;//第二个商店从50golds开始涨价
    store_price_0 += vars.BuyTimes_0;
    store_price_2 += vars.BuyTimes_1 * 2;
    switch (vars.store_no)
    {
    case 0:
        //商店0，第一个提升能力的商店
        printf("尊敬的勇士您好，如果您有%d金币，这里可以提升您的能力！\n", store_price_0);
        printf("通过按下123三个键可以选择增加的项目：\n");
        printf("1.提升500生命值\n");
        printf("2.提升3点攻击力\n");
        printf("3.提升3点防御力\n");
        printf("4.离开\n");
        choice = _getch();
        switch (choice)
        {
        case '1':
            if (Braver.gold >= store_price_0)
            {
                Braver.gold -= store_price_0;
                Braver.hp += 500;
                vars.BuyTimes_0++;
                store_price_0++;
                break;
            }
            else
            {
                vars.hint_msg = "您的金币不够！";
                break;
            }
        case '2':
            if (Braver.gold >= store_price_0)
            {
                Braver.gold -= store_price_0;
                Braver.at += 3;
                vars.BuyTimes_0++;
                store_price_0++;
                break;
            }
            else
            {
                vars.hint_msg = "您的金币不够！";
                break;
            }
        case '3':
            if (Braver.gold >= store_price_0)
            {
                Braver.gold -= store_price_0;
                Braver.df += 3;
                vars.BuyTimes_0++;
                store_price_0++;
                break;
            }
            else
            {
                vars.hint_msg = "您的金币不够！";
                break;
            }
        case '4':
            break;
        default:
            vars.hint_msg = "请输入正确的选项！";
            break;

        }break;
    case 2:
        //商店2，第三个提升能力的商店
        printf("尊敬的勇士您好，如果您有%d金币，这里可以提升您的能力！\n", store_price_2);
        printf("通过按下123三个键可以选择增加的项目：\n");
        printf("1.提升800生命值\n");
        printf("2.提升6点攻击力\n");
        printf("3.提升6点防御力\n");
        printf("4.离开\n");
        choice = _getch();
        switch (choice)
        {
        case '1':
            if (Braver.gold >= store_price_2)
            {
                Braver.gold -= store_price_2;
                Braver.hp += 800;
                vars.BuyTimes_1++;
                store_price_2 = store_price_2 + 2;
                break;
            }
            else
            {
                vars.hint_msg = "您的金币不够！";
                break;
            }
        case '2':
            if (Braver.gold >= store_price_2)
            {
                Braver.gold -= store_price_2;
                Braver.at += 6;
                vars.BuyTimes_1++;
                store_price_2 = store_price_2 + 2;
                break;
            }
            else
            {
                vars.hint_msg = "您的金币不够！";
                break;
            }
        case '3':
            if (Braver.gold >= store_price_2)
            {
                Braver.gold -= store_price_2;
                Braver.df += 6;
                vars.BuyTimes_1++;
                store_price_2 = store_price_2 + 2;
                break;
            }
            else
            {
                vars.hint_msg = "您的金币不够！";
                break;
            }
        case '4':
            break;
        default:
            vars.hint_msg = "请输入正确的选项！";
            break;
        }break;
    }
}
int main()
{
    game_init();//游戏开始
    while (true)
    {
        if (result == 0)
        {
            printf("WSAD分别对应上下左右，输入控制人物行走：\n");
            input_char = _getch();
            if (input_char == 65) 
                result = handle_keypress(0);//左
            else if (input_char == 87)
                result = handle_keypress(1);//上
            else if (input_char == 68)
                result = handle_keypress(2);//右
            else if (input_char == 83)
                result = handle_keypress(3);//下
            else
                continue;
        }
        // 返回操作状态:
        else if (result == 1) {
            printf("游戏结束！");
            result = 2;
        }
        if (result == 0) { //0为可以操作
            print_floor();
        }
        else if (result == 1) { //1为对话模式,暂未实现此功能
            print_floor();
            //show_dialog();暂无定义此功能
        }
        else if (result == 2) { //2为game_over,游戏结束
            break;
        }
        else if (result == 3) { //3为正在开门中
            result = 0;
            print_floor();
        }
        else if (result == 4) { //4为上下楼转场
            result = 0;
            print_floor();
        }
        else if (result == 5) { //5为战斗，后续会加入战斗动画
            result = 0;
            print_floor();
        }
        else if (result == 6) { //6为打开获得物品界面
            result = 0;
            print_floor();
        }
        else if (result == 7) { //7为开启商店处理
            while (choice !='4')
            {
                print_floor();
                handle_store();
            }
            choice = '0';
            vars.hint_msg = " ";
            result = 0;
            print_floor();
        }
    }
    return 0;
}
