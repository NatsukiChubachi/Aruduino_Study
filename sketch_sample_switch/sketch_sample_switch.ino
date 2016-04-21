// 定義部分
const int iIntervalTime = 1000;

int iLedMode = -1;

// 初期設定
void setup() 
{
  // put your setup code here, to run once:
  pinMode( 2, INPUT );
  
  // 8番をOutputに設定する
  pinMode( 8, OUTPUT );
}

// 断続処理（メイン部分）
void loop() 
{  
  // put your main code here, to run repeatedly:
  if ( digitalRead(2) == HIGH )
  {
    // ボタンの入力を感知し、モードをONにする
    iLedMode = 1;
  }

  if ( iLedMode == -1 )
  {
    // モードがONでないときはLOWのまま
    digitalWrite( 8, LOW );
    delay( iIntervalTime );
  }
  else
  {
    // 8番ピンの出力を1000ミリ秒間隔で切り替える
    digitalWrite( 8, HIGH );
    delay( iIntervalTime );
    digitalWrite( 8, LOW );
    delay( iIntervalTime );
  }
}


