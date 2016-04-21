// 定義部分
const int iIndexPinOutput = 8;
const int iIntervalTime = 1000;

int iLedMode = -1;

// 初期設定
void setup() 
{
  // put your setup code here, to run once:
  // 8番をOutputに設定する
  pinMode( iIndexPinOutput, OUTPUT );
}

// 断続処理（メイン部分）
void loop() 
{  
  // put your main code here, to run repeatedly:
  // 8番ピンの出力を1000ミリ秒間隔で切り替える
  digitalWrite( iIndexPinOutput, HIGH );
  delay( iIntervalTime );
  digitalWrite( iIndexPinOutput, LOW );
  delay( iIntervalTime );
}


