unit Basa;

interface

uses
  ASDVector,ASDSprites,ASDType,GameType,ASDHeader,OpenGL,ASDLine;

type
  TGameEngine=class;
  TBot=class;
  TAmmo=class;
  TWeaponBot=class;
  TAmmoClass=class of TAmmo;
  TBotClass=class of TBot;
  TTeamEngine=class;
  TTeamBot=class;
  TTeam=class;
  TLauncherBot=class;
  TLauncherBotClass=class of TLauncherBot;
  TSparks=class;

  TBotEvent=procedure(Sender:TBot) of object;
  TAmmoEvent=procedure(Sender:TAmmo) of object;
  TWeaponBotEvent=procedure(Sender:TWeaponBot) of object;

  TGameEngine=class(TSpriteEngine)
  private
    FAmmos:TSpriteEngine;
    FBots:TSpriteEngine;
    FAnimi:TSpriteEngine;
    FTeams:TTeamEngine;
    FLines:TLineEngine;
    FGameRect:TRect;
    //FIT: Real; //Время между последним двигом и ляпом
    //FLMT: Real; //Время последнего двига
    //FLDT: Real; //Время последнего кино-ляпа
    //FPM: Real;
    //отношение прошедшего времени с момента двига к интервалу между двигами
  protected
    procedure InitList;
  public
    constructor Init;
    destructor Destroy; override;
    procedure CollisionRect;
    procedure CollisionAmmo;
    procedure CollisionBot;
    procedure Dead; override;
    procedure Draw; override;
    procedure Move; override;
    property Bots:TSpriteEngine read FBots;
    property Ammos:TSpriteEngine read FAmmos;
    property Animi:TSpriteEngine read FAnimi;
    property Team:TTeamEngine read FTeams;
    property Lines:TLineEngine read FLines;
    //property LastMoveTime: Real read FLMT;
    //property LastDrawTime: Real read FLDT;
    //property InterpolationTime: Real read FIT; //Суть, думаю такая же
  end;

  TBot=class(TSprite)
  private
    FGame:TGameEngine;
    FOnCollision:TBotEvent;
    FRadius:Real;
    FOnDead:TBotEvent;
    FColor:TRGBA;
    FTex:ITexImage;
    FLastDrawPos:TVector;
    FAngle:Real;
    FMass:Real;
    FPosition:TVector;
    FVector:TVector;
  protected
    procedure Hit(Ammo:TAmmo); virtual;
    procedure DoMove; override;
  public
    constructor Create(AParent:TSprite); override;
    property Position:TVector read FPosition write FPosition;
    property Vector:TVector read FVector write FVector;
    property DX:Real read FVector.X write FVector.X;
    property DY:Real read FVector.Y write FVector.Y;
    property X:Real read FPosition.X write FPosition.X;
    property Y:Real read FPosition.Y write FPosition.Y;
    property Game:TGameEngine read FGame;
    property OnCollision:TBotEvent read FOnCollision write FOnCollision;
    property OnDead:TBotEvent read FOnDead write FOnDead;
    property Radius:Real read FRadius write FRadius;
    property Color:TRGBA read FColor write FColor;
    property Tex:ITexImage read FTex write FTex;
    property Mass:Real read FMass write FMass;
    procedure DoDraw; override;
    procedure DoCollisionRect; virtual;
    procedure Free; override;
  end;

  TWeaponBot=class(TBot)
  private
    FAllAmmo:Integer;
    FInterval:Integer;
    FTimePos:Integer;
    FOnTimer:TWeaponBotEvent;
    FEnabledTimer:Boolean;
    FLastAmmo:TAmmo;
    FBotsEngine:TSpriteEngine;
    FForceAmmo:Real;
  protected
    procedure DoTimer; virtual;
    procedure DoMove; override;
    procedure Hit(Ammo:TAmmo); override;
    procedure DoHitToBot(Bot:TWeaponBot); virtual;
  public
    constructor Create(AParent:TSprite); override;
    property AllAmmo:Integer read FAllAmmo;
    property Interval:Integer read FInterval write FInterval;
    property TimePos:Integer read FTimePos;
    property EnabledTimer:Boolean read FEnabledTimer write FEnabledTimer;
    property OnTimer:TWeaponBotEvent read FOnTimer write FOnTimer;
    property LastAmmo:TAmmo read FLastAmmo;
    property BotsEngine:TSpriteEngine read FBotsEngine;
    property ForceAmmo:Real read FForceAmmo write FForceAmmo;
  end;

  TAmmo=class(TBot)
  private
    FOwner:TTeamBot;
    FAmmoEngine:TSpriteEngine;
    FForce:Real;
  protected
    procedure DoHit(Bot:TBot); virtual;
  public
    constructor Create(AParent:TSprite); override;
    constructor Init(Owner:TTeamBot; V:TVector; Color:TRGBA; Force:Real=
      1);
    property Force:Real read FForce write FForce;
    property Owner:TTeamBot read FOwner;
    property AmmoEngine:TSpriteEngine read FAmmoEngine;
    procedure Dead; override;
    procedure DoDraw; override;
  end;

  TAnimBot=class(TBot)
  private
    FOwner:TBot;
    FAnimiSpeed:Real;
    FAnimiPos:Real;
    FAnimiCount:Real;
    FAnimiEngine:TSpriteEngine;
  protected
    procedure DoMove; override;
    procedure DoAnimi; virtual;
  public
    constructor Create(AParent:TSprite); override;
    constructor Init(Owner:TBot);
    property AnimiSpeed:Real read FAnimiSpeed write FAnimiSpeed;
    property AnimiPos:Real read FAnimiPos write FAnimiPos;
    property AnimiCount:Real read FAnimiCount write FAnimiCount;
    property Owner:TBot read FOwner;
    property AnimiEngine:TSpriteEngine read FAnimiEngine;
  end;

  TTeamEngine=class(TSpriteEngine)
  private
    function GetBots(Index:Integer):TTeam;
  protected
    procedure DoDraw; override;
    procedure DoMove; override;
  public
    constructor Create(AParent:TSprite); override;
    property Teams[Index:Integer]:TTeam read GetBots; default;
    function FindTeam(Name:TString32):TTeam;
  end;

  TTeam=class(TSprite)
  private
    FTeamColor:TRGBA;
    FName:TString32;
    FTeamEngine:TTeamEngine;
    FGame:TGameEngine;
    FLastBot:TTeamBot;
    FLeader:TLauncherBot;
    FBotCount:Integer;
    FTarget:TTeam;
    FTeamTex:ITexImage;
    FFragCount:Integer;
    procedure SetLeader(const Value:TLauncherBot);
  protected
    procedure AddBot(Bot:TTeamBot);
    procedure DelBot(Bot:TTeamBot);
    procedure AddFrag(Ammo:TAmmo; Bot:TBot);
  public
    constructor Create(AParent:TSprite); override;
    constructor Init(AParent:TSprite; AColor:TRGBA; AName:TString32);
    property TeamColor:TRGBA read FTeamColor write FTeamColor;
    property Name:TString32 read FName write FName;
    property Game:TGameEngine read FGame;
    property TeamEngine:TTeamEngine read FTeamEngine;
    property LastBot:TTeamBot read FLastBot;
    property BotCount:Integer read FBotCount;
    property Target:TTeam read FTarget write FTarget;
    property TeamTex:ITexImage read FTeamTex;
    property FragCount:Integer read FFragCount;
    property Leader:TLauncherBot read FLeader write SetLeader;
    procedure Dead; override;
  end;

  TTeamBot=class(TWeaponBot)
  private
    FTeam:TTeam;
    procedure SetTeam(const Value:TTeam);
  public
    constructor Init(ATeam:TTeam);
    property Team:TTeam read FTeam write SetTeam;
    procedure DoDraw; override;
    procedure Dead; override;
  end;

  TLauncherBot=class(TTeamBot)
  private
    FAmmoCount:Integer;
    FLife:Real;
    FPriority:Integer;
    FTick:Integer;
    FTarget:TLauncherBot;
    FWeapon:TAmmoClass;
    FTickCreate:Integer;
    FFragCount:Integer;
    procedure KillAmmo(Sender:TBot);
    procedure SetPriority(const Value:Integer);
    procedure SetTarget(const Value:TLauncherBot);
  protected
    procedure DoMove; override;
    procedure DoAction; virtual;
    procedure Hit(Ammo:TAmmo); override;
    procedure DoShot(Ammo:TAmmo); virtual;
    procedure DoHitToBot(Bot:TWeaponBot); override;
    procedure EnemyDetected(Enemy:TLauncherBot); virtual;
  public
    constructor Create(AParent:TSprite); override;
    property Target:TLauncherBot read FTarget write SetTarget;
    property AmmoCount:Integer read FAmmoCount write FAmmoCount;
    property Priority:Integer read FPriority write SetPriority;
    property Life:Real read FLife write FLife;
    property Weapon:TAmmoClass read FWeapon write FWeapon;
    property TickCreate:Integer read FTickCreate;
    property FragCount:Integer read FFragCount;
    procedure Shot(var V:TVector); virtual;
  end;

  TShotBot=class(TLauncherBot)
  private
    FAmmoSpeed:Real;
  protected
    procedure DoShot(Ammo:TAmmo); override;
    procedure KillAmmo(Sender:TBot);
  public
    constructor Create(AParent:TSprite); override;
    property AmmoSpeed:Real read FAmmoSpeed write FAmmoSpeed;
    procedure Shot(var V:TVector); override;
  end;

  TBestBot=class(TShotBot)
  protected
    procedure EnemyDetected(Enemy:TLauncherBot); override;
  end;

  //ChainGun - Метоавтомат
  //Rocket Launcher

  TRocketAmmo=class(TAmmo)
  private
    FTick:Integer;
    FPriority:Integer;
    FAddAlfa:Real;
    FTarget:TLauncherBot;
    FSteepAlfa:Real;
    procedure SetPriority(const Value:Integer);
    procedure SetTarget(const Value:TLauncherBot);
  protected
    procedure DoAction; virtual;
    procedure DoMinAction; virtual;
    procedure DoMove; override;
    procedure DoHit(Bot:TBot); override;
  public
    constructor Create(AParent:TSprite); override;
    property Priority:Integer read FPriority write SetPriority;
    property AddAlfa:Real read FAddAlfa write FAddAlfa;
    property Target:TLauncherBot read FTarget write SetTarget;
  end;

  TExplosion=class(TAnimBot)
  private
    FForce:Real;
    FAddAngle:Real;
    FAngle:Real;
  protected
    procedure DoDraw; override;
    procedure DoAnimi; override;
  public
    constructor Create(AParent:TSprite); override;
    constructor Init(Owner:TBot; Force:Real);
    property Force:Real read FForce;
    property AddAngle:Real read FAddAngle write FAddAngle;
    property Angle:Real read FAngle write FAngle;
  end;

  { TSparks }
  TSparkRec=record
    ID:Word; //Номер {только зачем он мне}
    P:TVector; //Позиция
    V:TVector; //Скорость
    C:TRGBA; //Цвет
    D:Boolean; //Мертв?
    F:Real; //Угол поворота
    O:Real; //Угловая скорость
    R:Real; //Радиус
  end;
  PSparkArray=^TSparkArray;
  TSparkArray=array[0..0] of TSparkRec;

  TSparks=class(TAnimBot)
  private
    FSparks:PSparkArray;
    FCountSpark:Integer;
  protected
    procedure DoMove; override;
    procedure DoDraw; override;
    procedure Dead; override;
  public
    constructor Create(AParent:TSprite); override;
    constructor Init(Owner:TBot; Count:Integer; MaxR:Real=5);
    property CountSpark:Integer read FCountSpark;
  end;

function TestColisionBot(const A,B:TVector; const RA,RB:Real):Boolean;
procedure DrawQuads(Tex:ITexImage; P:TVector; C:TRGBA; R,A:Real);
function RndVector(Mag:Real):TVector;
procedure CollisionBool(P1,P2:TVector; M1,M2:Real; var V1,V2:TVector);

var
  RocketTex:ITexImage;
  AmmoTex:ITexImage;
  BotTex:ITexImage;
  TeamTex:ITexImage;
  ExplosionTex:ITexImage;
  SparkTex:ITexImage;
  SelBox:ITexImage;
  LeaderTex:ITexImage;
  DrawL:GLint;

implementation

uses GameApp,ASDUtils;

procedure CollisionBool(P1,P2:TVector; M1,M2:Real; var V1,V2:TVector);
//Абсолютно упругое столкновение
var
  Buf:TVectorAngle;
  MyV,SpV:TVector;
  U1,U2,Alfa:Real;
  Va1,Va2:TVectorAngle;
begin
  // Пререводим векторы скорости в радиальную систему(РС)
  Va1:=VectorToVectorAngle(V1);
  Va2:=VectorToVectorAngle(V2);
  // Находим угол наклона относительно начала координат
  MyV:=VectorSub(P2,P1);
  Alfa:=ArcTan2(MyV.Y,MyV.X);
  // Поворачиваем координаты 1-го на угол MyVec.Alfa-Alfa
  MyV.X:=Va1.Dlina*Cos((Va1.Alfa-Alfa));
  MyV.Y:=Va1.Dlina*Sin((Va1.Alfa-Alfa));
  // Поворачиваем координаты 2-го на угол SpVec.Alfa-Alfa
  SpV.X:=Va2.Dlina*Cos((Va2.Alfa-Alfa));
  SpV.Y:=Va2.Dlina*Sin((Va2.Alfa-Alfa));
  // Применяем Формулу
  U1:=((M1-M2)*MyV.X+2*M2*SpV.X)/(M1+M2);
  U2:=((M2-M1)*SpV.X+2*M1*MyV.X)/(M1+M2);
  // Поворачиваем векторы скорости 1-го на место
  Buf:=VectorToVectorAngle(MakeVector(U1,MyV.Y));
  Va1.Alfa:=Buf.Alfa+Alfa;
  Va1.Dlina:=Buf.Dlina;
  // Поворачиваем векторы скорости 2-го на место
  Buf:=VectorToVectorAngle(MakeVector(U2,SpV.Y));
  Va2.Alfa:=Buf.Alfa+Alfa;
  Va2.Dlina:=Buf.Dlina;
  // Пререводим векторы скорости из РС в декартовую систему
  V1:=VectorAngleToVector(Va1);
  V2:=VectorAngleToVector(Va2);
end;

function RndVector(Mag:Real):TVector;
var
  Alfa:Real;
begin
  Alfa:=RndReal(-Pi,Pi,0.001);
  Result.X:=Mag*Cos(Alfa);
  Result.Y:=Mag*Sin(Alfa);
end;

{(*}// - No Format
procedure DrawQuads(Tex:ITexImage; P:TVector; C:TRGBA; R,A:Real);
begin
  glPushMatrix;
  glTranslated(P.X,P.Y,0);
  glRotated(A,0,0,1);
  Tex.Enable;
  glColor4(PGLubyte(@C));
  glScaled(R*2,R*2,1);
  glCallList(DrawL);
  Tex.Disable;
  glPopMatrix;
end;
{*)}

function TestColisionBot(const A,B:TVector; const RA,RB:Real):Boolean;
begin
  Result:=((A.X-B.X)*(A.X-B.X)+(A.Y-B.Y)*(A.Y
    -B.Y))<=((RA+RB)*(RA+RB));
end;

function PointInRect(const Point:TVector; const Rect:TRect):Boolean;
begin
  Result:=(Point.X>=Rect.Left)and
    (Point.X<=Rect.Right)and
    (Point.Y>=Rect.Top)and
    (Point.Y<=Rect.Bottom);
end;

{ TGameEngine }

procedure TGameEngine.CollisionRect;
var
  I:Integer;
  //Bot: TBot;
begin
  for I:=0 to FAmmos.Count-1 do
    TBot(FAmmos[I]).DoCollisionRect;
  for I:=0 to FBots.Count-1 do
    TBot(FBots[I]).DoCollisionRect;
end;

procedure TGameEngine.CollisionAmmo;
var
  I,J:Integer;
  A:TAmmo;
  B:TBot;
begin
  for I:=0 to FAmmos.Count-1 do
  begin
    A:=TAmmo(Ammos[I]);
    if A.Deaded then
      Continue;
    for J:=0 to FBots.Count-1 do
    begin
      B:=TBot(Bots[J]);
      if B.Deaded then
        Continue;
      if TestColisionBot(A.Position,B.Position,A.Radius,B.Radius) then
      begin
        A.DoHit(B);
        if A.Deaded then
          Break;
      end;
    end;
  end;
end;

procedure TGameEngine.CollisionBot;
var
  I,J:Integer;
  A,B:TWeaponBot;
begin
  for I:=0 to Bots.Count-2 do
  begin
    A:=TWeaponBot(Bots[I]);
    if A.Deaded then
      Continue;
    for J:=I+1 to Bots.Count-1 do
    begin
      B:=TWeaponBot(Bots[J]);
      if B.Deaded then
        Continue;
      if TestColisionBot(A.Position,B.Position,A.Radius,B.Radius) then
      begin
        CollisionBool(A.Position,B.Position,A.Mass,B.Mass,A.FVector,
          B.FVector);
        A.DoHitToBot(B);
        B.DoHitToBot(A);
        if A.Deaded then
          Break;
      end;
    end;
  end;
end;

constructor TGameEngine.Init;
begin
  inherited Create(nil);
  InitList;
  FGameRect:=Rect(0,0,Window.Width,Window.Height);
  FAmmos:=TSpriteEngine.Create(Self); //||   Пули   ||//
  FBots:=TSpriteEngine.Create(Self); //||   Боты   ||//
  FAnimi:=TSpriteEngine.Create(Self); //|| Анимация ||//
  FTeams:=TTeamEngine.Create(Self); //||  Отряды  ||//
  FLines:=TLineEngine.Create(Self); //||  Карта   ||//
end;

procedure TGameEngine.Dead;
var
  I:Integer;
begin
  for I:=0 to Count-1 do
  begin
    Items[I].Dead;
  end;
end;

procedure TGameEngine.Draw;
var
  I:Integer;
begin
  //FLDT := GetTime;
  //FIT := FLDT - FLMT;
  //FPM := FIT * UPS;
  inherited;
end;

procedure TGameEngine.Move;
begin
  //FLMT := GetTime;
  inherited;
end;

destructor TGameEngine.Destroy;
begin
  inherited;
end;

procedure TGameEngine.InitList;
begin
  DrawL:=glGenLists(1);
  glNewList(DrawL,GL_COMPILE);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0);
  glVertex2f(-0.5,-0.5);
  glTexCoord2d(1,0);
  glVertex2f(0.5,-0.5);
  glTexCoord2d(1,1);
  glVertex2f(0.5,0.5);
  glTexCoord2d(0,1);
  glVertex2f(-0.5,0.5);
  glEnd;
  glEndList;
end;

{ TBot }

constructor TBot.Create(AParent:TSprite);
begin
  inherited;
  if (Engine is TGameEngine) then
  begin
    FGame:=TGameEngine(Engine);
  end;
  if (Engine.Engine is TGameEngine) then
  begin
    FGame:=TGameEngine(Engine.Engine);
  end;
  FRadius:=7;
  FColor:=clWhite;
  FTex:=BotTex;
end;

procedure TBot.DoCollisionRect;
var
  //  M: TRect;
  I:Integer;
  F:Boolean;
begin
  if FGame=nil then
    Exit;
  F:=False;
  {  M := FGame.FGameRect;
    R := FRadius;
    if (X + FRadius > M.Right) or (X - FRadius < M.Left) then
    begin
      DX := -DX;
      F := True;
    end;
    if (Y + FRadius > M.Bottom) or (Y - FRadius < M.Top) then
    begin
      DY := -DY;
      F := True;
    end;}
  for I:=0 to FGame.FLines.Count-1 do
  begin
    if DoCollision(FPosition,FVector,FGame.FLines[I],Radius+1) then
    begin
      F:=True;
    end;
  end;
  if not F then
    Exit;
  if Assigned(OnCollision) then
    OnCollision(Self);
end;

procedure TBot.DoDraw;
begin
  if FTex=nil then
    Exit;
  FLastDrawPos.X:=X{ + DX * FGame.FPM};
  FLastDrawPos.Y:=Y{ + DY * FGame.FPM};
  DrawQuads(FTex,FLastDrawPos,FColor,10,FAngle);
end;

procedure TBot.DoMove;
begin
  X:=X+DX;
  Y:=Y+DY;
end;

procedure TBot.Free;
begin
  if Assigned(FOnDead) then
    FOnDead(Self);
  inherited Free;
end;

procedure TBot.Hit(Ammo:TAmmo);
begin
  if not Deaded then Dead else Exit;
  Ammo.Owner.Team.AddFrag(Ammo,Self);
end;

{ TWeaponBot }

constructor TWeaponBot.Create(AParent:TSprite);
begin
  if AParent is TGameEngine then
  begin
    FBotsEngine:=TGameEngine(AParent).FBots;
    AParent:=FBotsEngine;
  end;
  inherited;
  FInterval:=60;
  FTimePos:=Random(FInterval);
  FEnabledTimer:=False;
  FForceAmmo:=1;
  FMass:=1000;
end;

procedure TWeaponBot.DoHitToBot(Bot:TWeaponBot);
begin
  //TExplosion.Create();
end;

procedure TWeaponBot.DoMove;
begin
  inherited;
  DoTimer;
end;

procedure TWeaponBot.DoTimer;
begin
  if not EnabledTimer then
    Exit;
  Inc(FTimePos);
  if FTimePos<FInterval then
    Exit;
  FTimePos:=0;
  if Assigned(FOnTimer) then
    FOnTimer(Self);
end;

procedure TWeaponBot.Hit(Ammo:TAmmo);
begin
  inherited;
  //TAnimBot.Init(Self);
  TExplosion.Init(Self,FForceAmmo*3.5);
  TSparks.Init(Self,Round(FForceAmmo*6),7);
end;

{ TAmmo }

constructor TAmmo.Create(AParent:TSprite);
begin
  if AParent is TGameEngine then
  begin
    FAmmoEngine:=TGameEngine(AParent).FAmmos;
    AParent:=FAmmoEngine;
    inherited Create(AParent);
  end
  else
    inherited;
  FTex:=AmmoTex;
  FMass:=0.1;
end;

procedure TAmmo.Dead;
begin
  inherited;
  FOwner.UnLock;
end;

procedure TAmmo.DoDraw;
begin
  if FTex=nil then
    Exit;
  FAngle:=VectorGetAlfa(Vector)*180/pi;
  FLastDrawPos.X:=X{ + DX * FGame.FPM};
  FLastDrawPos.Y:=Y{ + DY * FGame.FPM};
  DrawQuads(FTex,FLastDrawPos,FColor,8,FAngle);
end;

procedure TAmmo.DoHit(Bot:TBot);
begin
  TExplosion.Init(Self,FForce);
  if Bot<>nil then
  begin
    Bot.Hit(Self);
    Bot.Vector:=VectorAdd(Bot.Vector,VectorMul(Vector,Mass/Bot.Mass));
  end;
  Dead;
end;

constructor TAmmo.Init(Owner:TTeamBot; V:TVector; Color:TRGBA; Force:
  Real);
begin
  FOwner:=Owner;
  Inc(FOwner.FAllAmmo);
  FOwner.Lock;
  Create(FOwner.Game);
  FColor:=Color;
  Vector:=V;
  Radius:=2;
  FForce:=Force;
  Position:=VectorAdd(FOwner.Position,VectorSetDlina(V,Radius+FOwner.Radius
    +1));
end;

{ TAnimBot }

constructor TAnimBot.Create(AParent:TSprite);
begin
  if AParent is TGameEngine then
  begin
    FAnimiEngine:=TGameEngine(AParent).FAnimi;
    AParent:=FAnimiEngine;
  end;
  inherited;
end;

procedure TAnimBot.DoAnimi;
begin
  FRadius:=FRadius-FAnimiSpeed*10;
  if FRadius<0 then
    Dead;
end;

procedure TAnimBot.DoMove;
begin
  inherited;
  if FAnimiCount<>0 then
  begin
    FAnimiPos:=FAnimiPos+FAnimiSpeed;
    DoAnimi;
    if FAnimiPos>FAnimiCount then
    begin
      FAnimiPos:=0;
    end;
  end;
end;

constructor TAnimBot.Init(Owner:TBot);
begin
  FOwner:=Owner;
  Create(FOwner.FGame);
  Position:=FOwner.Position;
  Vector:=FOwner.Vector;
  FRadius:=FOwner.FRadius;
  FColor:=FOwner.FColor;
  FAnimiSpeed:=1/85;
  FAnimiCount:=FRadius/10;
end;

{ TTeamEngine }

constructor TTeamEngine.Create(AParent:TSprite);
begin
  inherited;
  Moved:=False;
  Visible:=False;
end;

procedure TTeamEngine.DoDraw;
begin
  //Not Action
end;

procedure TTeamEngine.DoMove;
begin
  //Not Action
end;

function TTeamEngine.FindTeam(Name:TString32):TTeam;
var
  I:Integer;
begin
  for I:=0 to count-1 do
    if Teams[I].Name=Name then
    begin
      Result:=Teams[I];
      Exit;
    end;
  Result:=nil;
end;

function TTeamEngine.GetBots(Index:Integer):TTeam;
begin
  Result:=TTeam(Items[Index]);
end;

{ TTeam }

procedure TTeam.AddBot(Bot:TTeamBot);
begin
  Inc(FBotCount);
  if FLastBot<>nil then
    FLastBot.UnLock;
  FLastBot:=Bot;
  FLastBot.Lock;
end;

procedure TTeam.AddFrag(Ammo:TAmmo; Bot:TBot);
var
  Hero,Enemy:TLauncherBot;
begin
  Inc(FFragCount);
  if Ammo.Owner.Deaded then Exit;
  Hero:=TLauncherBot(Ammo.Owner); Enemy:=TLauncherBot(Bot); Inc(Hero.FFragCount);
  if Leader=nil then Leader:=Hero else
    if (Hero.FragCount>Leader.FragCount)or(Leader.Deaded) then Leader:=Hero;
  Hero.FLife:=Hero.FLife+10;
  {-=Enemy Award=-}
  Inc(Hero.FAmmoCount,Enemy.AmmoCount div 10);
  {if Enemy.FragCount>=5 then }Hero.FLife:=Hero.FLife+Enemy.FragCount;
  if Enemy.FragCount>=10 then Inc(Hero.FAmmoCount,50);
  if Enemy.FragCount>=20 then
  begin
    if Hero.Priority>15 then Hero.FPriority:=Hero.FPriority-1;
  end;
  {-=Ammo Award=-}
  if Hero.FFragCount=10 then Inc(Hero.FAmmoCount,200);
  {-=Best Award=-}
  if Hero.FFragCount>10 then
  begin
    if Hero.FForceAmmo<2 then
    begin
      Hero.FForceAmmo:=Hero.FForceAmmo+0.2;
      //if Hero.FForceAmmo>2 then Hero.FForceAmmo:=2;
    end;
    //if Hero.FPriority>20 then Hero.FPriority:=Hero.FPriority-1;
  end;
end;

constructor TTeam.Create(AParent:TSprite);
begin
  if AParent is TGameEngine then
  begin
    FGame:=TGameEngine(AParent);
    FTeamEngine:=TGameEngine(AParent).FTeams;
    AParent:=FTeamEngine;
  end;
  inherited;
  Moved:=False;
  Visible:=False;
  FBotCount:=0;
  FFragCount:=0;
  FTeamTex:=Basa.TeamTex;
end;

procedure TTeam.Dead;
begin
  inherited;
  if FLastBot<>nil then
    FLastBot.UnLock;
end;

procedure TTeam.DelBot(Bot:TTeamBot);
begin
  Dec(FBotCount);
  if Bot=FLastBot then
  begin
    FLastBot.UnLock;
    FLastBot:=nil;
  end;
end;

constructor TTeam.Init(AParent:TSprite; AColor:TRGBA; AName:TString32);
begin
  FTeamColor:=AColor;
  FName:=AName;
  Create(AParent);
end;

procedure TTeam.SetLeader(const Value:TLauncherBot);
begin
  if FLeader=Value then Exit;
  if FLeader<>nil then FLeader.UnLock;
  FLeader:=Value;
  if FLeader<>nil then FLeader.Lock;
end;

{ TTeamBot }

procedure TTeamBot.Dead;
begin
  inherited;
  FTeam.DelBot(Self);
end;

procedure TTeamBot.DoDraw;
var
  S:string;
  W,H:Integer;
begin
  inherited;
  if FTeam.FTeamTex=nil then
    Exit;
  DrawQuads(FTeam.FTeamTex,FLastDrawPos,FTeam.FTeamColor,4,0);
  if Self=FTeam.Leader then
  begin
    DrawQuads(LeaderTex,FLastDrawPos,FTeam.FTeamColor,12+1*Sin(App.Tick*2*pi/UPS),-App.Tick*1.5);
    DrawQuads(LeaderTex,FLastDrawPos,FTeam.FTeamColor,12+1*Sin(App.Tick*2*pi/UPS),-App.Tick*1.5);
    DrawQuads(LeaderTex,FLastDrawPos,FTeam.FTeamColor,12+1*Sin(1.5*App.Tick*2*pi/UPS),App.Tick*2);
    DrawQuads(LeaderTex,FLastDrawPos,FTeam.FTeamColor,12+1*Sin(1.5*App.Tick*2*pi/UPS),App.Tick*2);
  end;
end;

constructor TTeamBot.Init(ATeam:TTeam);
begin
  FTeam:=ATeam;
  Create(FTeam.FGame);
  FTeam.AddBot(Self);
end;

procedure TTeamBot.SetTeam(const Value:TTeam);
begin
  if FTeam<>nil then
    FTeam.DelBot(Self);
  FTeam:=Value;
  if FTeam<>nil then
    FTeam.AddBot(Self);
end;

{ TLauncherBot }

constructor TLauncherBot.Create(AParent:TSprite);
begin
  inherited;
  FLife:=1;
  FAmmoCount:=500;
  Priority:=20;
  FWeapon:=TAmmo;
  FTickCreate:=App.Tick;
  FFragCount:=0;
end;

procedure TLauncherBot.DoAction;
var
  V:TVector;
begin
  if FTarget<>nil then
  begin
    if not FTarget.Deaded then
    begin
      V:=VectorSub(FTarget.Position,Position);
      V:=VectorSetDlina(V,3.5);
      Shot(V);
    end
    else
    begin
      SetTarget(nil);
    end;
  end;
  //Коммандная Цель
  {else if Team.Target <> nil then
  begin
    SetTarget(TLauncherBot(Team.Target.LastBot));
  end;}
end;

procedure TLauncherBot.DoHitToBot(Bot:TWeaponBot);
begin
  EnemyDetected(TLauncherBot(Bot));
end;

procedure TLauncherBot.DoMove;
begin
  inherited;
  Inc(FTick);
  if FTick>FPriority then
  begin
    FTick:=0;
    DoAction;
  end;
end;

procedure TLauncherBot.DoShot(Ammo:TAmmo);
begin
  //Not Action
  Ammo.Force:=FForceAmmo;
end;

procedure TLauncherBot.EnemyDetected(Enemy:TLauncherBot);
begin
  if Enemy=nil then Exit;
  if (Enemy.Team=Team) then Enemy:=Enemy.Target;
  if Enemy=nil then Exit;
  if Enemy.Deaded then Exit;
  if Target<>nil then
  begin
    if VectorABDlina(Position,Enemy.Position)<VectorABDlina(Position,Target.Position) then
      SetTarget(Enemy);
  end
  else
    SetTarget(Enemy);
end;

procedure TLauncherBot.Hit(Ammo:TAmmo);
var
  Enemy:TLauncherBot;
  L1,L2:Real;
begin
  if Ammo=nil then
  begin
    inherited;
    Exit;
  end;
  Life:=Life-Ammo.Force;
  if Life<=0 then
    inherited
  else if Ammo.Owner<>nil then
    if Ammo.Owner is TLauncherBot then
    begin
      Enemy:=Ammo.Owner as TLauncherBot;
      EnemyDetected(Enemy);
    end;
end;

procedure TLauncherBot.KillAmmo(Sender:TBot);
begin
  if Sender is TAmmo then
    TAmmo(Sender).DoHit(nil)
  else
    Sender.Dead;
end;

procedure TLauncherBot.SetPriority(const Value:Integer);
begin
  FPriority:=Value;
  FTick:=Random(FPriority);
end;

procedure TLauncherBot.SetTarget(const Value:TLauncherBot);
begin
  if (FTarget=Value) then Exit;
  if FTarget<>nil then FTarget.UnLock;
  FTarget:=Value;
  if FTarget<>nil then FTarget.Lock;
  //if FTeam.Target=nil then FTeam.Target:=FTarget.FTeam;
end;

procedure TLauncherBot.Shot(var V:TVector);
var
  NewAmmo:TAmmo;
begin
  if FAmmoCount>0 then
    Dec(FAmmoCount)
  else
    Exit;
  NewAmmo:=Weapon.Init(Self,V,FColor);
  NewAmmo.FOnDead:=FOnDead;
  NewAmmo.FOnCollision:=KillAmmo;
  //FMass := FMass - NewAmmo.FMass;
  {FVector:=VectorSub(FVector,VectorMul(NewAmmo.Vector,NewAmmo.FMass/
    FMass));}
  DoShot(NewAmmo);
  FLastAmmo:=NewAmmo;
end;

{ TShotBot }

constructor TShotBot.Create(AParent:TSprite);
begin
  inherited;
  FAmmoSpeed:=3.05;
  FForceAmmo:=1.17;
end;

procedure TShotBot.DoShot(Ammo:TAmmo);
begin
  inherited;
  Ammo.FOnCollision:=KillAmmo;
end;

procedure TShotBot.KillAmmo(Sender:TBot);
begin
  if Sender is TAmmo then
    TAmmo(Sender).DoHit(nil)
  else
    Sender.Dead;
end;

procedure TShotBot.Shot(var V:TVector);
  function RaschotPerechwata(T,P:TVector; VT:TVector; Scor:Real; var
    Ugol:Real; var N:Real; var C:TVector):Boolean;
  var
    S:TVector;
    VR1,VR2,VP1,VP2:Real;
    R:TVectorAngle;
  begin
    R:=VectorToVectorAngle(VectorSub(P,T));
    VT:=VectorAddAlfa(VT,-R.Alfa);
    VP1:=VT.Y;
    VR1:=VT.X;

    if Scor<VP1 then
    begin
      Result:=false;
      exit;
    end;
    VP2:=VP1;
    if abs(Scor)<abs(VP2) then
    begin
      Result:=false;
      exit;
    end;
    VR2:=sqrt(sqr(Scor)-sqr(VP2));
    if VR2<=VR1 then
    begin
      Result:=false;
      exit;
    end;

    Ugol:=ArcTan2(VR2,VP2);

    Ugol:=Ugol+R.Alfa;
    Result:=true;
    N:=(R.Dlina)/(VR2-VR1);
    S:=VectorMul(VT,N);
    C:=VectorAdd(T,S);
  end;
var
  F:Boolean;
  T,P:TVector;
  VT:TVector;
  Speed:Real;
  Ugol:Real;
  N:Real;
  C:TVector;
begin
  T:=Target.Position;
  P:=Position;
  VT:=Target.Vector;
  Speed:=FAmmoSpeed;
  F:=RaschotPerechwata(T,P,VT,Speed,Ugol,N,C);
  V:=VectorAngleToVector(MakeVectorAngle(Ugol+pi/2,Speed));
  if F then
    inherited;
end;

{ TRocketAmmo }

constructor TRocketAmmo.Create(AParent:TSprite);
begin
  inherited;
  if FOwner<>nil then
    if TLauncherBot(FOwner).Target<>nil then
      SetTarget(TLauncherBot(FOwner).FTarget);
  Priority:=10;
  FAddAlfa:=Pi/120;
  FTex:=RocketTex;
  FMass:=0.5;
end;

procedure TRocketAmmo.DoAction;
var
  A:TVector;
  RA:Real;
begin
  if FTarget=nil then
  begin
    SetTarget(TLauncherBot(Owner).Target);
    Exit;
  end;
  if FTarget.Deaded then
  begin
    SetTarget(nil);
    FSteepAlfa:=0;
  end
  else
  begin
    A:=VectorSub(FTarget.Position,Position);
    RA:=VectorCompareAlfa(A,Vector);
    if Abs(RA)>FAddAlfa*FPriority then
      FSteepAlfa:=(RA/Abs(RA))*FAddAlfa
    else
      FSteepAlfa:=RA/FPriority;
  end;
end;

procedure TRocketAmmo.DoHit(Bot:TBot);
begin
  TSparks.Init(Self,Round(FForce*5));
  if Bot<>nil then
  begin
    Bot.Hit(Self);
  end;
  Dead;
end;

procedure TRocketAmmo.DoMinAction;
begin
  Vector:=VectorAddAlfa(Vector,FSteepAlfa);
end;

procedure TRocketAmmo.DoMove;
begin
  inherited;
  Inc(FTick);
  if FTick>FPriority then
  begin
    FTick:=0;
    DoAction;
  end;
  DoMinAction;
end;

procedure TRocketAmmo.SetPriority(const Value:Integer);
begin
  FPriority:=Value;
  FTick:=Random(FPriority);
end;

procedure TRocketAmmo.SetTarget(const Value:TLauncherBot);
begin
  if FTarget<>nil then
    FTarget.UnLock;
  FTarget:=Value;
  if FTarget<>nil then
    FTarget.Lock;
end;

{ TExplosion }
const
  OneExploseR=10;

constructor TExplosion.Create(AParent:TSprite);
begin
  inherited;
  FTex:=ExplosionTex;
end;

procedure TExplosion.DoAnimi;
begin
  FRadius:=FAnimiPos*OneExploseR*4;
  FAngle:=FAngle+FAddAngle;
  if FAnimiPos/FAnimiCount>0.75 then
  begin
    FColor.A:=Round(255-(FAnimiPos-FAnimiCount*0.75)*255/(FAnimiCount
      *0.25));
  end;
  if FAnimiPos>FAnimiCount then
  begin
    Dead;
  end;
end;

procedure TExplosion.DoDraw;
begin
  glPushMatrix;
  OGL.Blend(BT_ADD);
  if FTex=nil then
    Exit;
  DrawQuads(FTex,Position,FColor,FRadius,FAngle);
  glPopMatrix;
end;

constructor TExplosion.Init(Owner:TBot; Force:Real);
begin
  inherited Init(Owner);
  FColor:=RGBA(255,255,255,255);
  FForce:=Force/1.5;
  FAnimiCount:=FForce/4;
  //Vector:=VectorSetDlina(Vector,0.5);
  Vector:=NulVector;
  FRadius:=0;
  FAddAngle:=RndReal(-3,3);
  FAngle:=RndReal(-180,180,0.001);
end;

{ TSparks }

constructor TSparks.Create(AParent:TSprite);
begin
  inherited;
  FTex:=SparkTex;
end;

procedure TSparks.Dead;
begin
  inherited Dead;
end;

procedure TSparks.DoDraw;
var
  I:Integer;
begin
  if FTex=nil then
    Exit;
  glPushMatrix;
  OGL.Blend(BT_ADD);
  FTex.Enable;
  for I:=0 to FCountSpark-1 do
  begin
    with FSparks[I] do
    begin
      if D then
        Continue;
      glPushMatrix;
      glTranslated(P.X,P.Y,0);
      glRotated(F,0,0,1);
      glColor4(PGLubyte(@C));
      glScaled(R*2,R*2,1);
      glCallList(DrawL);
      glPopMatrix;
    end;
  end;
  FTex.Disable;
  glPopMatrix;
end;

procedure TSparks.DoMove;
var
  I:Integer;
begin
  for I:=0 to FCountSpark-1 do
    with FSparks[I] do
    begin
      if D then
        Continue;
      F:=F+O;
      P:=VectorAdd(P,V);
      //V := VectorSetDlina(V,VectorMagnitude(V)-0.001);
      Dec(C.A,1);
      D:=C.A=0;
      if D then
      begin
        FAnimiPos:=FAnimiPos+1;
      end;
    end;
  if FAnimiPos>=AnimiCount then
    Dead;
end;

constructor TSparks.Init(Owner:TBot; Count:Integer; MaxR:Real=5);
var
  I:Integer;
begin
  inherited Init(Owner);
  Vector:=NulVector;
  FSparks:=GetMemory(Count*SizeOf(TSparkRec));
  FAnimiPos:=0;
  FCountSpark:=Count;
  FAnimiCount:=FCountSpark;
  for I:=0 to FCountSpark-1 do
    with FSparks[I] do
    begin
      ID:=I;
      P:=Position;
      V:=RndVector(RndReal(0.2,0.6,0.01));
      //C := RGBA(255, 255, 255, Random(50) + 206);
      C:=FColor;
      C.A:=Random(50)+206;
      D:=False;
      F:=RndReal(0,360,0.001);
      O:=RndReal(0,360/UPS,0.1);
      R:=RndReal(2,MaxR);
    end;
end;

{ TBestBot }

procedure TBestBot.EnemyDetected(Enemy:TLauncherBot);
begin
  //inherited EnemyDetected(Enemy);
  if Enemy=nil then Exit;
  if (Enemy.Team=Team) then Enemy:=Enemy.Target;
  if Enemy=nil then Exit;
  if Enemy.Deaded then Exit;
  if Enemy=Target then Exit;
  if (Enemy.Life>Life*2)and(VectorABDlina(Position,Enemy.Position)>50) then Exit;
  if Target<>nil then
  begin
    if VectorABDlina(Position,Enemy.Position)<VectorABDlina(Position,Target.Position) then
      SetTarget(Enemy);
  end
  else SetTarget(Enemy);
end;

end.