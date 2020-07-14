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
    //�����˺�ֵ��
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

    // ���ز���״̬��0Ϊ���Բ�����1Ϊ�Ի�ģʽ����δʵ�֣���2Ϊgame_over, 3Ϊ����, 4Ϊ����¥, 5Ϊս��, 6Ϊ��ʾ�����Ʒ��Ϣ, 7Ϊ�����̵괦��
    int target_pos;
    int old_data = -1;
    if (key_no == 0) { //����
        Braver.face = 1; //0/1/2/3�ֱ������������
        if (Braver.pos_x == 0)
            return 0;
        else
            target_pos = Braver.pos_y * X + (Braver.pos_x - 1);
    }
    else if (key_no == 1) { //����
        Braver.face = 3;
        if (Braver.pos_y == 0)
            return 0;
        else
            target_pos = (Braver.pos_y - 1) * X + Braver.pos_x;
    }
    else if (key_no == 2) { //����
        Braver.face = 2;
        if (Braver.pos_x == X - 1)
            return 0;
        else
            target_pos = Braver.pos_y * X + (Braver.pos_x + 1);
    }
    else if (key_no == 3) { //����
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
        //ƽ�� ֱ���߹�ȥ
        Braver.pos_x = target_pos % X;
        Braver.pos_y = target_pos / X;
        return 0;
    }
    else if ((Tower[Braver.floor][target_pos] >= 1 && Tower[Braver.floor][target_pos] <= 9) || Tower[Braver.floor][target_pos] == 41 || Tower[Braver.floor][target_pos] == 43) {
        //ײǽ λ�ò��仯
        return 0;
    }
    else if (Tower[Braver.floor][target_pos] == 10) {
        //��¥
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
        //��¥
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
        //�������һ���뿪��ֱ��Game Over
        vars.end_no = 1;
        return 1;
    }
    else if (Tower[Braver.floor][target_pos] == 14) {
        vars.hint_msg = "3��֮������ݣ���δ������ɡ�";
        return 1;
    }
    
    else if (Tower[Braver.floor][target_pos] == 21) {
        //����
        if (Braver.ykey >= 1) {
            Braver.ykey -= 1;
            Tower[Braver.floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 22) {
        //����
        if (Braver.bkey >= 1) {
            Braver.bkey -= 1;
            Tower[Braver.floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 23) {
        //����
        if (Braver.rkey >= 1) {
            Braver.rkey -= 1;
            Tower[Braver.floor][target_pos] = 0;
        }
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 25) {
        //����
        Tower[Braver.floor][target_pos] = 0;
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 26) {
        //��ǽ��������ܻῼ����������ʵ�֣���ʱ����
        Tower[Braver.floor][target_pos] = 0;
        return 3;
    }
    else if (Tower[Braver.floor][target_pos] == 31) {
        //��Կ��
        Tower[Braver.floor][target_pos] = 0;
        Braver.ykey += 1;
        vars.gain_item_msg = "�����һ�ѻ�Կ��";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 32) {
        //��Կ��
        Tower[Braver.floor][target_pos] = 0;
        Braver.bkey += 1;
        vars.gain_item_msg = "�����һ����Կ��";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 33) {
        //��Կ��
        Tower[Braver.floor][target_pos] = 0;
        Braver.rkey += 1;
        vars.gain_item_msg = "�����һ�Ѻ�Կ��";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 34) {
        //СѪƿ ��ţ�34
        Tower[Braver.floor][target_pos] = 0;
        Braver.hp += 50;
        vars.gain_item_msg = "�����СѪƿ ����ֵ����50";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 35) {
        //��Ѫƿ ��ţ�35
        Tower[Braver.floor][target_pos] = 0;
        Braver.hp += 200;
        vars.gain_item_msg = "����˴�Ѫƿ ����ֵ����200";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 36) {
        //�챦ʯ ��ţ�36
        Tower[Braver.floor][target_pos] = 0;
        Braver.at += 1;
        vars.gain_item_msg = "����˺챦ʯ ����������1��";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 37) {
        //����ʯ ��ţ�37
        Tower[Braver.floor][target_pos] = 0;
        Braver.df += 1;
        vars.gain_item_msg = "���������ʯ ����������1��";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 38) {
        //���� ��ţ�38
        Tower[Braver.floor][target_pos] = 0;
        Braver.at += 10;
        vars.gain_item_msg = "��������� ����������10��";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 39) {
        //���� ��ţ�39
        Tower[Braver.floor][target_pos] = 0;
        Braver.df += 10;
        vars.gain_item_msg = "��������� ����������10��";
        return 6;
    }
    else if (Tower[Braver.floor][target_pos] == 42) {
        //�̵괦��1
        vars.store_no = 0;
        return 7;
    }
    else if (Tower[Braver.floor][target_pos] == 43) {
        //�̵괦��2
        vars.store_no = 1;
        return 7;
    }
    else if (Tower[Braver.floor][target_pos] == 44) {
        //�̵괦��3
        vars.store_no = 2;
        return 7;
    }
    else if (Tower[Braver.floor][target_pos] == 45) {
        //�̵괦��4
        vars.store_no = 3;
        return 7;
    }
    else if (Tower[Braver.floor][target_pos] >= 51) {
        //����
        int monster_id = Tower[Braver.floor][target_pos] - 51;
        int damage = calc_damage(monster_id);
        if (damage == -2) {
            //�ڴ򲻹�ʱ���������κδ���
            vars.hint_msg = "�㻹���ܴ����";
            return 0;
        }
        else if (damage == -1 || damage >= Braver.hp) {
            //�ڴ򲻹�ʱ���������κδ���
            vars.hint_msg = "�㻹���ܴ����";
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
void handle_store()// �̵괦������̵�1:���Ϊ0;�����̵�1:���Ϊ1;����̵�2:���Ϊ2;�����̵�2:���Ϊ3;)
{
    int store_price_0 = 20;//��һ���̵��20golds��ʼ�Ǽ�
    int store_price_2 = 50;//�ڶ����̵��50golds��ʼ�Ǽ�
    store_price_0 += vars.BuyTimes_0;
    store_price_2 += vars.BuyTimes_1 * 2;
    switch (vars.store_no)
    {
    case 0:
        //�̵�0����һ�������������̵�
        printf("�𾴵���ʿ���ã��������%d��ң����������������������\n", store_price_0);
        printf("ͨ������123����������ѡ�����ӵ���Ŀ��\n");
        printf("1.����500����ֵ\n");
        printf("2.����3�㹥����\n");
        printf("3.����3�������\n");
        printf("4.�뿪\n");
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
                vars.hint_msg = "���Ľ�Ҳ�����";
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
                vars.hint_msg = "���Ľ�Ҳ�����";
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
                vars.hint_msg = "���Ľ�Ҳ�����";
                break;
            }
        case '4':
            break;
        default:
            vars.hint_msg = "��������ȷ��ѡ�";
            break;

        }break;
    case 2:
        //�̵�2�������������������̵�
        printf("�𾴵���ʿ���ã��������%d��ң����������������������\n", store_price_2);
        printf("ͨ������123����������ѡ�����ӵ���Ŀ��\n");
        printf("1.����800����ֵ\n");
        printf("2.����6�㹥����\n");
        printf("3.����6�������\n");
        printf("4.�뿪\n");
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
                vars.hint_msg = "���Ľ�Ҳ�����";
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
                vars.hint_msg = "���Ľ�Ҳ�����";
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
                vars.hint_msg = "���Ľ�Ҳ�����";
                break;
            }
        case '4':
            break;
        default:
            vars.hint_msg = "��������ȷ��ѡ�";
            break;
        }break;
    }
}
int main()
{
    game_init();//��Ϸ��ʼ
    while (true)
    {
        if (result == 0)
        {
            printf("WSAD�ֱ��Ӧ�������ң���������������ߣ�\n");
            input_char = _getch();
            if (input_char == 65) 
                result = handle_keypress(0);//��
            else if (input_char == 87)
                result = handle_keypress(1);//��
            else if (input_char == 68)
                result = handle_keypress(2);//��
            else if (input_char == 83)
                result = handle_keypress(3);//��
            else
                continue;
        }
        // ���ز���״̬:
        else if (result == 1) {
            printf("��Ϸ������");
            result = 2;
        }
        if (result == 0) { //0Ϊ���Բ���
            print_floor();
        }
        else if (result == 1) { //1Ϊ�Ի�ģʽ,��δʵ�ִ˹���
            print_floor();
            //show_dialog();���޶���˹���
        }
        else if (result == 2) { //2Ϊgame_over,��Ϸ����
            break;
        }
        else if (result == 3) { //3Ϊ���ڿ�����
            result = 0;
            print_floor();
        }
        else if (result == 4) { //4Ϊ����¥ת��
            result = 0;
            print_floor();
        }
        else if (result == 5) { //5Ϊս�������������ս������
            result = 0;
            print_floor();
        }
        else if (result == 6) { //6Ϊ�򿪻����Ʒ����
            result = 0;
            print_floor();
        }
        else if (result == 7) { //7Ϊ�����̵괦��
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
