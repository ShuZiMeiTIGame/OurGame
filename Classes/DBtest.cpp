#include "DBtest.h"
#include "DB.h"
USING_NS_CC;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	if(DB::sharedDB()->OpenDBWithFileName("save.db")) //打开一个数据库，如果该数据库不存在，则创建一个数据库文件  
{
 
    //创建表
    DB::sharedDB()->CreateTableWithContent("create table playerinfo( ID integer primary key autoincrement, playername nvarchar(32),playerscores int ) "); 
    DB::sharedDB()->CreateTableWithContent("create table gamepass( ID integer primary key autoincrement, passindex int, passstarts int ,passisunlocked int  ) "); 
 
    //插入数据  
    DB::sharedDB()->InsertTableDataWithContent(" insert into playerinfo( playername,playerscores  ) values ( 'default', 683500 ) "); 
    DB::sharedDB()->InsertTableDataWithContent(" insert into playerinfo( playername,playerscores ) values ( 'default2', 4 ) ");  
    
    DB::sharedDB()->InsertTableDataWithContent(" insert into gamepass( passindex,passstarts,passisunlocked ) values ( 1, 2, 1 ) "); 
    DB::sharedDB()->InsertTableDataWithContent(" insert into gamepass( passindex,passstarts,passisunlocked ) values ( 2, 3, 0 ) ");  
    DB::sharedDB()->InsertTableDataWithContent(" insert into gamepass( passindex,passstarts,passisunlocked ) values ( 3, 0, 0 ) "); 
    
   // 获取数据  
   /*int scores=DB::sharedDB()->GetPlayerInfoScores(" select *  from  playerinfo  where  playername ='default' ");  
   int starts=DB::sharedDB()->GetPassInfoStartsWithIndex(" select *  from  gamepass  where passindex =2 ");
   bool isLocked1=DB::sharedDB()->GetPassInfoIsUnlockedWithIndex(" select *  from  gamepass  where  passindex =1 ");
   bool isLocked3=DB::sharedDB()->GetPassInfoIsUnlockedWithIndex(" select *  from  gamepass  where  passindex =3 ");
   CCLOG("= %d =",scores);

   CCLOG("= %d =",starts);
   (isLocked1==true)?( CCLOG("= has unlock =")):(CCLOG("= is locked ="));
   (isLocked3==true)?( CCLOG("= has unlock =")):(CCLOG("= is locked ="));*/
 


// 删除数据
   DB::sharedDB()->DeleteTableDataWithContent("delete from playerinfo where playername = 'default2' "); 

// 更新数据
   DB::sharedDB()->UpdateTableDataWithContent("update gamepass set passisunlocked=1  where passindex = 2 ");
 

// 关闭数据库 
   DB::sharedDB()->CloseDB();
}

 



    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
