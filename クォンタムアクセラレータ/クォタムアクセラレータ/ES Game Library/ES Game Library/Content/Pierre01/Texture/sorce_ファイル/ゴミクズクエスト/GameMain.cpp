// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here6
	WindowTitle(_T("ES Game Library"));
	//x1280*y720
	TAITORU = GraphicsDevice.CreateSpriteFromFile(_T("GOMI.png"));

		
	Fin = GraphicsDevice.CreateSpriteFromFile(_T("1Fin.png"));
	yuka = GraphicsDevice.CreateSpriteFromFile(_T("YUKA.jpg"));
	player = GraphicsDevice.CreateSpriteFromFile(_T("player2.png"));
	a = GraphicsDevice.CreateSpriteFromFile(_T("ttt.png"));
	b = GraphicsDevice.CreateSpriteFromFile(_T("z.png"));
	c = GraphicsDevice.CreateSpriteFromFile(_T("tt.png"));
	d = GraphicsDevice.CreateSpriteFromFile(_T("ggg.png"));
	e = GraphicsDevice.CreateSpriteFromFile(_T("aaa.png"));
	f = GraphicsDevice.CreateSpriteFromFile(_T("lll.png"));
	EF = GraphicsDevice.CreateSpriteFromFile(_T("th.psd"));
	chara = GraphicsDevice.CreateSpriteFromFile(_T("aaa.png"));
	kyara = GraphicsDevice.CreateSpriteFromFile(_T("z.png"));
	tate = GraphicsDevice.CreateSpriteFromFile(_T("maru.png"));
	se1 = SoundDevice.CreateSoundFromFile(_T("HI.wav"));
	se2 = SoundDevice.CreateSoundFromFile(_T("ƒNƒŠƒA.wav"));
	se3 = SoundDevice.CreateSoundFromFile(_T("ƒQ[ƒ€ƒI[ƒo[.wav"));
	bgm = SoundDevice.CreateMusicFromFile(_T("t.wav"));
	bgmgame = SoundDevice.CreateMusicFromFile(_T("ƒQ[ƒ€’†.wav"));
	v = GraphicsDevice.CreateSpriteFromFile(_T("ggg.png"));
	x = GraphicsDevice.CreateSpriteFromFile(_T("ppp.png"));
	vv = GraphicsDevice.CreateSpriteFromFile(_T("ggg.png"));
	xx = GraphicsDevice.CreateSpriteFromFile(_T("ppp.png"));
	w = GraphicsDevice.CreateSpriteFromFile(_T("ttt.png"));
	ww = GraphicsDevice.CreateSpriteFromFile(_T("z.png"));
	moji = GraphicsDevice.CreateSpriteFont(_T("impact"), 100);
	l = GraphicsDevice.CreateSpriteFromFile(_T("ttt.png"));
	ll = GraphicsDevice.CreateSpriteFromFile(_T("ppp.png"));
	lll = GraphicsDevice.CreateSpriteFromFile(_T("ggg.png"));
	bgm->Play();
	TAITORU_x_ = 0.0f, TAITORU_y_ = 0.0f;
	ssss_x_ = 0.0f, ssss_y_ = 0.0f;
	yuka_x_ = 0.0f, yuka_y_ = 0.0f;
	yuka_x_ = 0.0f, yuka_y_ = 0.0f;
	Fin_x_ = 0.0f, Fin_y_ = 0.0f;
	player_x_ = 540.0f, player_y_ = 350.0f;
	a_x_ = -800.0f, a_y_ = 0.0f;
	b_x_ = 1500.0f, b_y_ = 0.0f;
	c_x_ = 0.0f, c_y_ = -900.0f;
	d_x_ = 0.0f, d_y_ = 1100.0f;
	e_x_ = -350.0f, e_y_ = -350.0f;
	f_x_ = -6000.0f, f_y_ = 0.0f;
	chara_x_ = 0.0f, chara_y_ = 0.0f;
	player_state_ = 10;
	game_scene_ = 0;
	v_state_ = 0;
	vv_state_ = 2;
	w_state_ = 20;
	l_state_ = 25;
	v_x_ = 0.0f, v_y_ = 500;
	vv_x_ = 1080.0f, vv_y_ = 600;
	w_x_ = -200.0f, w_y_ = 0.0f;
	l_x_ = -300.0f,l_y_ = 0.0f;
	timer = 60;

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	KeyboardState key_state = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	if (game_scene_ == 0) {
		if (key_buffer.IsPressed(Keys_Enter)) {
			game_scene_ = 1;
			player_state_ = 10;
			player_x_ = 540.0f, player_y_ = 350.0f;
			a_x_ = -700.0f, a_y_ = 0.0f;
			b_x_ = 1500.0f, b_y_ = 0.0f;
			c_x_ = 0.0f, c_y_ = -800.0f;
			d_x_ = 0.0f, d_y_ = 1000.0f;
			e_x_ = -350.0f, e_y_ = -350.0f;
			f_x_ = -6000.0f, f_y_ = 0.0f;
			v_x_ = 0.0f, v_y_ = 800;
			vv_x_ = 1080.0f, vv_y_ = 800;
			w_x_ = -200.0f, w_y_ = 0.0f;
			l_x_ = -300.0f, l_y_ = 0.0f;
			timer = 60;
			/*bgmgame->Play();*/
		}
	}
	else if (game_scene_ == 1) {
		//if (key_buffer.IsPressed(Keys_Enter)) {
		//	bgmgame->Stop();
		//	game_scene_ = 2;
		//	se3->Play();
		//}

		if (player_state_ != 11) {
			count++;

			if (count % 60 == 0) {
				timer--;
				count = 60;
				if (timer < 0) {
					bgmgame->Stop();
					game_scene_ = 3;
					se2->Play();
				}
			}

			if (player_x_ < -100) {
				player_x_ = -100;
			}
			if (player_x_ > 1140) {
				player_x_ = 1140;
			}
			if (player_y_ < -100) {
				player_y_ = -100;
			}
			if (player_y_ > 600) {
				player_y_ = 600;
			}
			if (player_state_ == 10) {
				if (key_state.IsKeyDown(Keys_Left)) {
					player_x_ = player_x_ - 10.0f;
				}
				if (key_state.IsKeyDown(Keys_Right)) {
					player_x_ = player_x_ + 10.0f;
				}
				if (key_state.IsKeyDown(Keys_Down)) {
					player_y_ = player_y_ + 10.0f;
				}
				if (key_state.IsKeyDown(Keys_Up)) {
					player_y_ = player_y_ - 10.0f;
				}
			}

			a_x_ = a_x_ + 5.0f;
			if (a_x_ > 1280.0f) {
				a_x_ = MathHelper_Random(-300, -600);
				a_y_ = MathHelper_Random(0, 600);

			};

			b_x_ = b_x_ - 5.0f;
			if (b_x_ < -500.0f) {
				b_x_ = MathHelper_Random(1300, 2000);
				b_y_ = MathHelper_Random(0, 650);
			};
			c_y_ = c_y_ + 5.0f;
			if (c_y_ > 820.0f) {
				c_x_ = MathHelper_Random(0, 1280);
				c_y_ = MathHelper_Random(-800, -1280);
			};
			d_y_ = d_y_ - 5.0f;
			if (d_y_ < -100.0f) {
				d_x_ = MathHelper_Random(0, 1280);
				d_y_ = MathHelper_Random(900, 2000);
			};
			e_x_ = e_x_ + 5.0f;
			e_y_ = e_y_ + 5.0f;
			if (e_y_ > +900.0f) {
				e_x_ = MathHelper_Random(-100, 600);
				e_y_ = MathHelper_Random(-500, -900);
			}

			if (timer < 30) {
				if (v_state_ == 0) {
					v_x_ = v_x_ + 1.5f;
					v_y_ = v_y_ - 20.0f;
					if (v_y_ < -100.0f) {
						v_state_ = 1;
					}
				}
			}

			if (v_state_ == 1) {
				v_x_ = v_x_ + 1.5f;
				v_y_ = v_y_ + 30.0f;
				if (v_y_ > 600.0f) {
					v_state_ = 0;
				}
			}

			if (timer < 30) {
				if (vv_state_ == 2) {
					vv_x_ = vv_x_ - 1.5f;
					vv_y_ = vv_y_ - 20.0f;
					if (vv_y_ < -100.0f) {
						vv_state_ = 3;
					}
				}
			}

			if (vv_state_ == 3) {
				vv_x_ = vv_x_ - 1.5f;
				vv_y_ = vv_y_ + 30.0f;
				if (vv_y_ > 600.0f) {
					vv_state_ = 2;
				}
			}

			if (timer < 30) {
				if (w_state_ == 20) {
					w_x_ = w_x_ + 20.0f;
					w_y_ = w_y_ + 1.0f;
					if (w_x_ > 1280.0f) {
						w_state_ = 21;
					}
				}
			}

			if (w_state_ == 21) {
				w_x_ = w_x_ - 30.0f;
				w_y_ = w_y_ + 1.0f;
				if (w_x_ < 0.0f) {
					w_state_ = 20;
				}
			}
			if (timer < 10) {
				if (l_state_ == 25) {
					l_x_ = l_x_ + 30.0f;
					if (l_x_ > 1100.0f) {
						l_state_ = 26;
					}
				}
			}

			if (timer < 3) {
				if (l_state_ == 26) {
					l_x_ = l_x_ - 4.0f;
					l_y_ = l_y_ + 200.0f;
					if (l_y_ > 600.0f) {
						l_state_ = 27;
					}
				}
			}

			if (l_state_ == 27) {
				l_x_ = l_x_ - 4.0f;
				l_y_ = l_y_ - 200.0f;
				if (l_y_ < 0.0f) {
					l_state_ = 26;
				}
			}

			f_x_ = f_x_ + 1.0f;

			if (a_x_ + 20 > player_x_ + 120.0f || a_x_ + 180.0f < player_x_ + 80 ||
				a_y_ + 20 > player_y_ + 120.0f || a_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (b_x_ + 20 > player_x_ + 120.0f || b_x_ + 180.0f < player_x_ + 80 ||
				b_y_ + 20 > player_y_ + 120.0f || b_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (c_x_ + 20 > player_x_ + 120.0f || c_x_ + 180.0f < player_x_ + 80 ||
				c_y_ + 20 > player_y_ + 120.0f || c_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (d_x_ + 20 > player_x_ + 120.0f || d_x_ + 180.0f < player_x_ + 80 ||
				d_y_ + 20 > player_y_ + 120.0f || d_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (e_x_ + 20 > player_x_ + 120.0f || e_x_ + 180.0f < player_x_ + 80 ||
				e_y_ + 20 > player_y_ + 120.0f || e_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (f_x_ > player_x_ + 120.0f || f_x_ + 600.0f < player_x_ + 80 ||
				f_y_ > player_y_ + 120.0f || f_y_ + 600.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (v_x_ + 20 > player_x_ + 120.0f || v_x_ + 180.0f < player_x_ + 80 ||
				v_y_ + 20 > player_y_ + 120.0f || v_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (x_x_ + 20 > player_x_ + 120.0f || x_x_ + 180.0f < player_x_ + 80 ||
				x_y_ + 20 > player_y_ + 120.0f || x_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (vv_x_ + 20 > player_x_ + 120.0f || vv_x_ + 180.0f < player_x_ + 80 ||
				vv_y_ + 20 > player_y_ + 120.0f || vv_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (xx_x_ + 20 > player_x_ + 120.0f || xx_x_ + 180.0f < player_x_ + 80 ||
				xx_y_ + 20> player_y_ + 120.0f || xx_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (w_x_ + 20 > player_x_ + 120.0f || w_x_ + 180.0f < player_x_ + 80 ||
				w_y_ + 20> player_y_ + 120.0f || w_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (ww_x_ + 20 > player_x_ + 120.0f || ww_x_ + 180.0f < player_x_ + 80 ||
				ww_y_ + 20> player_y_ + 120.0f || ww_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (l_x_ + 20 > player_x_ + 120.0f || l_x_ + 180.0f < player_x_ + 80 ||
				l_y_ + 20> player_y_ + 120.0f || l_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}

			if (ll_x_ + 20 > player_x_ + 120.0f || ll_x_ + 180.0f < player_x_ + 80 ||
				ll_y_ + 20> player_y_ + 120.0f || ll_y_ + 180.0f < player_y_ + 80) {

			}
			else {
				bgmgame->Stop();
				player_state_ = 11;
				se1->Play();
				gameover_count = 0;
			}
		}

		if (player_state_ == 11) {
			gameover_count++;
			if (gameover_count >= 180) {
				bgmgame->Stop();
				game_scene_ = 2;
				se3->Play();			
			}

		}
	}


	else if (game_scene_ == 2) {
		if (key_buffer.IsPressed(Keys_Space)) {
			game_scene_ = 0;
			/*bgm->Play();*/
		}
	}



	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();

	if (game_scene_ == 0) {
		SpriteBatch.Draw(*TAITORU, Vector3(TAITORU_x_, TAITORU_y_, 0.00f));
	}

	if (game_scene_ == 1) {

		SpriteBatch.Draw(*yuka, Vector3(yuka_x_, yuka_y_, 0.00f));
		if (player_state_ == 10) {
			SpriteBatch.Draw(*player, Vector3(player_x_, player_y_, 0.00f));
		}
		if (player_state_ == 11) {
			SpriteBatch.Draw(*EF, Vector3(player_x_, player_y_, 0.00f));
		}
		SpriteBatch.Draw(*a, Vector3(a_x_, a_y_, 0.00f));
		SpriteBatch.Draw(*b, Vector3(b_x_, b_y_, 0.00f));
		SpriteBatch.Draw(*c, Vector3(c_x_, c_y_, 0.00f));
		SpriteBatch.Draw(*d, Vector3(d_x_, d_y_, 0.00f));
		SpriteBatch.Draw(*e, Vector3(e_x_, e_y_, 0.00f));
		SpriteBatch.Draw(*f, Vector3(f_x_, f_y_, 0.00f));

		if (v_state_ == 0) {
			SpriteBatch.Draw(*v, Vector3(v_x_, v_y_, 0.00f));
		}

		if (v_state_ == 1) {
			SpriteBatch.Draw(*x, Vector3(v_x_, v_y_, 0.00f));
		}

		if (vv_state_ == 2) {
			SpriteBatch.Draw(*vv, Vector3(vv_x_, vv_y_, 0.00f));
		}

		if (vv_state_ == 3) {
			SpriteBatch.Draw(*xx, Vector3(vv_x_, vv_y_, 0.00f));
		}

		if (w_state_ == 20) {
			SpriteBatch.Draw(*w, Vector3(w_x_, w_y_, 0.00f));
		}

		if (w_state_ == 21) {
			SpriteBatch.Draw(*ww, Vector3(w_x_, w_y_, 0.00f));
		}

		if (l_state_ == 25) {
			SpriteBatch.Draw(*l, Vector3(l_x_, l_y_, 0.00f));
		}


		if (l_state_ == 26) {
			SpriteBatch.Draw(*ll, Vector3(l_x_, l_y_, 0.00f));
		}


		if (l_state_ == 27) {
			SpriteBatch.Draw(*lll, Vector3(l_x_, l_y_, 0.00f));
		}
		SpriteBatch.DrawString(moji	, Vector2(2.0f, 0.0f), Color(0, 0, 0), _T("Žc‚è:%d•b"), timer);		
		SpriteBatch.DrawString(moji, Vector2(0.0f, 2.0f), Color(0, 0, 0), _T("Žc‚è:%d•b"), timer);
		SpriteBatch.DrawString(moji, Vector2(-2.0f, 0.0f), Color(0, 0, 0), _T("Žc‚è:%d•b"), timer);
		SpriteBatch.DrawString(moji, Vector2(0.0f, -2.0f), Color(0, 0, 0), _T("Žc‚è:%d•b"), timer);
		SpriteBatch.DrawString(moji, Vector2(0.0f, 0.0f), Color(255, 255, 255), _T("Žc‚è:%d•b"), timer);
	}


	else if (game_scene_ == 2) {
		SpriteBatch.Draw(*ssss, Vector3(ssss_x_, ssss_y_, 0.00f));
	}

	else if (game_scene_ == 3) {
		SpriteBatch.Draw(*Fin, Vector3(Fin_x_, Fin_y_, 0.00f));
	}

	SpriteBatch.End();

	GraphicsDevice.EndScene();

	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;

	/*paint.SetPaintColor(Color(255, 0, 0));
	canvas.DrawArc(Rect(a_x_ + 0, a_y_ + 0, a_x_ + 100, a_y_ + 100), 0.0f, 0.0f, false, paint);*/
	//paint.SetPaintColor(Color(0, 0, 0));
	//canvas.DrawRect(Rect(v_x_ + 20, v_y_ + 20, v_x_ + 180, v_y_ + 180), paint);
	/*paint.SetPaintColor(Color(0, 0, 0));
	canvas.DrawRect(Rect(player_x_ + 80, player_y_ + 80, player_x_ + 120, player_y_ + 120), paint);
*/
	GraphicsDevice.UnlockCanvas();
}
