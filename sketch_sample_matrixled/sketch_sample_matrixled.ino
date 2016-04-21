// ROW側がCathord、COLUMN側がAnodeの8*8マトリクスLED
int iAnodePin[ 8 ] = { 10, 11, 12, 14, 15, 16, 17, 18 };
int iCathodePin[ 8 ] = { 2, 3, 4, 5, 6, 7, 8, 9 };

// 動作モード
int iLedMode = -1;

// 初期設定
void setup() 
{
  // put your setup code here, to run once:

  // 2番をInput設定にする
  pinMode( 13, INPUT );

  for ( int i = 0; i < 8; i++ )
  {
    pinMode( iAnodePin[i], OUTPUT );
    digitalWrite( iAnodePin[i], LOW );
  }

  for ( int i = 0; i < 8; i++ )
  {
    pinMode( iCathodePin[i], OUTPUT );
    digitalWrite( iCathodePin[i], HIGH );  
  }
}

// 断続処理（メイン部分）
void loop() 
{  
  if ( digitalRead(13) == HIGH )
  {
    // ボタンの入力を感知し、モードをONにする
    iLedMode = 1;
  }

  if ( iLedMode < 0 )
  {
    for ( int i=0; i<8; i++ )
    {
      for ( int j=0; j<8; j++ )
      {
        digitalWrite( iCathodePin[i], LOW );
        digitalWrite( iAnodePin[j], LOW );
      }
    }
    delay( 1000 );
  }
  else
  {
    for ( int i=0; i<8; i++ )
    {
      digitalWrite( iCathodePin[i], LOW );
    
      for ( int j=0; j<8; j++ )
      {

        digitalWrite( iAnodePin[j], HIGH );
        delay( 100 );
        digitalWrite( iAnodePin[j], LOW );
      }

      digitalWrite( iCathodePin[i], HIGH );
    }
  }
}


