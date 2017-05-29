#include "PlayMusic.h"

/* 播放音乐 */
void music()
{
    int i;
    char key;
    for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, 21 + i);
        printf("                             ");
    }

    PlaySound(TEXT("music\\南农校歌.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    Lyrics();
    while(1)
    {
        if((key = getch()) == 'z')
        {
            PlaySound(NULL, NULL, NULL);
            ClearTotal();
            break;
        }
    }
}

/* 歌词 */
void Lyrics()
{
    SetPosition(MARGIN_X + 22, 4);
    printf("钟山挺秀是你的风骨 长江浩然是你的雄魂");
    SetPosition(MARGIN_X + 22, 5);
    printf("荟萃五千年华夏文明 推出一代代神农传人");
    SetPosition(MARGIN_X + 24, 6);
    printf("啊！南京农业大学 啊！南京农业大学");
    SetPosition(MARGIN_X + 22, 7);
    printf("人民的衣食铭刻心中 祖国的强盛身当重任");
    SetPosition(MARGIN_X + 29, 8);
    printf("你把智慧撒向希望的田野");
    SetPosition(MARGIN_X + 27, 9);
    printf("用科学催动催动 现代化巨轮");

    SetPosition(MARGIN_X + 22, 11);
    printf("钟山挺秀是你的风骨 长江浩然是你的雄魂");
    SetPosition(MARGIN_X + 22, 12);
    printf("荟萃五千年华夏文明 推出一代代神农传人");
    SetPosition(MARGIN_X + 24, 13);
    printf("啊！南京农业大学 啊！南京农业大学");
    SetPosition(MARGIN_X + 22, 14);
    printf("光辉的誓言团结勤奋 闪亮的校训求实创新");
    SetPosition(MARGIN_X + 29, 15);
    printf("在跨世纪里程中迎接挑战");
    SetPosition(MARGIN_X + 27, 16);
    printf("为中华腾飞腾飞 拼搏奋进 奋进");

    SetPosition(MARGIN_X + 30, 18);
    printf("(按z键暂停播放并返回)");
}

