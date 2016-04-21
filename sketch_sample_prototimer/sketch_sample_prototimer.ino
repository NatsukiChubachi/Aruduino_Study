// ROW側がCathord、COLUMN側がAnodeの8*8マトリクスLED
int iAnodePin[ 8 ] = { 10, 11, 12, 14, 15, 16, 17, 18 };
int iCathodePin[ 8 ] = { 2, 3, 4, 5, 6, 7, 8, 9 };

// 動作モード
int iLedMode = -1;
int iRemainCounter = 0;

// 初期設定
void setup()
{
  // 2番をInput設定にする
  pinMode( 13, INPUT );

  // マトリクスLEDのピンをセットする
  for ( int i = 0; i < 8; i++ )
  {
    pinMode( iAnodePin[i], OUTPUT );
    digitalWrite( iAnodePin[i], LOW );
  }

  for ( int i = 0; i < 8; i++ )
  {
    pinMode( iCathodePin[i], OUTPUT );
    digitalWrite( iCathodePin[i], LOW );
  }
}

// 断続処理（メイン部分）
void loop()
{
  // 入力の取得
  if ( digitalRead(13) == HIGH )
  {
    // ボタンの入力を感知し、モードをONにする
    iLedMode = 1;
    iRemainCounter = (8 * 8) + 8;

    for ( int i = 0; i < 8; i++ )
    {
      digitalWrite( iCathodePin[i], HIGH );
      digitalWrite( iAnodePin[i], LOW );
    }
  }

  // モードによる分岐
  if ( iLedMode < 0 )
  {
    // OFFモード時はすべてのLEDをLOWにセットする
    for ( int i = 0; i < 8; i++ )
    {
      for ( int j = 0; j < 8; j++ )
      {
        digitalWrite( iCathodePin[i], LOW );
        digitalWrite( iAnodePin[j], LOW );
      }
    }

    // 1000ミリ秒待つ
    delay( 1000 );
  }
  else
  {
    int iIndex = 0;
    bool bOnCathode = false;

    while( iRemainCounter > 0 )
    {
      int iAnode = (iRemainCounter % 8);
      int iCathode = (iRemainCounter / 8);

      if( iCathode < 8 )
      {
        digitalWrite( iCathodePin[ iCathode ], LOW );    
      
        for ( int i=0; i<8; i++ ) digitalWrite( iAnodePin[i], HIGH );
        for ( int i=0; i<8; i++ )
        {
          if( i > iAnode ) digitalWrite( iAnodePin[i], HIGH ); 
          else digitalWrite( iAnodePin[i], LOW );
        }
      }
      
      // 1000ミリ秒待つ
      delay( 1000 );

      // 残り時間の減少
      iRemainCounter --;
      if ( iRemainCounter < 0 )
      {
        iRemainCounter = 0;
        iLedMode = -1;
      }
    }
  }
}


