#include "Defs.h"

LRESULT CALLBACK MainProcedure(HWND _hWnd, UINT _message, WPARAM _wp, LPARAM _lp)
{
	MainMenu _menu;

	switch (_message)
	{
	case WM_COMMAND:
	{
		switch (_wp)
		{
		case COMMANDS::OnPlayClicked:
		{	
			if (_menu.GetPlay()) DestroyWindow(_menu.GetPlay());
			std::pair<bool, HWND> _PlayResult = _menu.AddWindow(L"PlayWndClass", L"The Maze", _hWnd,
				[](HWND hWnd, UINT _playMsg, WPARAM _wp, LPARAM _lp) -> LRESULT {
					PlayWindow _start_menu;
					
					switch (_playMsg)
					{
					case WM_CREATE:
					{
						_start_menu.PlayDiffWidgets(hWnd);
						_start_menu.PlaySizeWidgets(hWnd);
						_start_menu.PlayBtnWidgets(hWnd);
						_start_menu.PlayGameModeWidgets(hWnd);
						SetWindowPos(hWnd, HWND_TOPMOST, 300, 200, 670, 360, NULL);

						break;
					}

					case WM_COMMAND:
					{
						switch (_wp)
						{
						case COMMANDS::OnPlayOkClicked:
						{
							PostMessage(hWnd, WM_CLOSE, NULL, NULL);
							if (_start_menu.GetTheMazeWnd()) DestroyWindow(_start_menu.GetTheMazeWnd());
							std::pair<bool, HWND> _PlayOkResult = _start_menu.AddWindow(L"PlayOkWndClass", L"The Maze", hWnd, 
								[](HWND hWndMaze, UINT _playOkMsg, WPARAM _wp, LPARAM _lp) -> LRESULT {
									if (_selectedMazeSize == NULL)
									{
										_transmittedMazeSize = _15x15Chosen;
									}
									TheMazeWindow ma(_transmittedMazeSize, _transmittedMazeSize);
									
									switch (_playOkMsg)
									{
									case WM_CREATE:
									{				
										if (_transmittedMazeSize == _15x15Chosen)
										{
											ma.StatisticsWidgets_15x15(hWndMaze);
											SetWindowPos(hWndMaze, HWND_TOPMOST, 0, 0, 670, 428, NULL);
										}
										else if (_transmittedMazeSize == _25x25Chosen)
										{
											ma.StatisticsWidgets_25x25(hWndMaze);
											SetWindowPos(hWndMaze, HWND_TOPMOST, 0, 0, 931, 689, NULL);
										}
										else if (_transmittedMazeSize == _40x40Chosen)
										{
											ma.StatisticsWidgets_40x40(hWndMaze);
											SetWindowPos(hWndMaze, HWND_TOPMOST, 0, 0, 1321, 1079, NULL);
										}

										break;
									}
									case WM_KEYDOWN:
									{
										switch (_wp)
										{
										case VK_UP:
										{
											

											break;
										}

										default:
											break;
										}

										break;
									}
									case WM_PAINT:
									{
										if (_SelectedMazeGameMode == _PlayerChoosen || _SelectedMazeGameMode == NULL)
										{
											srand((unsigned)time(NULL));
											ma.generateTree();
											ma.outFile();
											RECT _rect_1;
											GetClientRect(hWndMaze, &_rect_1);
											PAINTSTRUCT _ps_1;
											HDC _hdc_1 = BeginPaint(hWndMaze, &_ps_1);
											ma.draw(_hdc_1, hWndMaze, _rect_1);
											EndPaint(hWndMaze, &_ps_1);

											
										}
										else if (_SelectedMazeGameMode == _BotChoosen)
										{
											srand((unsigned)time(NULL));
											ma.generateTree();
											ma.outFile();
											RECT _rect_2;
											GetClientRect(hWndMaze, &_rect_2);
											PAINTSTRUCT _ps_2;
											HDC _hdc_2 = BeginPaint(hWndMaze, &_ps_2);
											ma.BotAlgorithm();
											ma.drawBotWay(_hdc_2, hWndMaze, _rect_2);
											EndPaint(hWndMaze, &_ps_2);

										}		
										break;
									}

									case WM_COMMAND:
									{
										StatisticsWindow sW;
										
										switch (_wp)
										{
										case COMMANDS::OnFinishClicked:
										{
											MessageBox(hWndMaze, L"The game has saved", L"The Maze", MB_OK);
											PostMessage(hWndMaze, WM_CLOSE, NULL, NULL);
											
											break;
										}

										default:
											break;
										}
										
										break;
									}
									case WM_CLOSE:
									{
										DestroyWindow(hWndMaze);
										
										break;
									}

									default:
										break;
									}
									return DefWindowProc(hWndMaze, _playOkMsg, _wp, _lp);
							});
							_start_menu.SetTheMazeWnd(_PlayOkResult.second);
							
							break;
						}
						case COMMANDS::_15x15Chosen:
						{
							_selectedMazeSize = _15x15Chosen;
							
							break;
						}
						case COMMANDS::_25x25Chosen:
						{
							_selectedMazeSize = _25x25Chosen;
							
							break;
						}
						case COMMANDS::_40x40Chosen:
						{
							_selectedMazeSize = _40x40Chosen;
							
							break;
						}
						case COMMANDS::OnPlayApplyClicked:
						{
							if (_selectedMazeSize != NULL)
							{
								_transmittedMazeSize = _selectedMazeSize;
							}
							
							break;
						}
						case COMMANDS::_PlayerChoosen:
						{
							_SelectedMazeGameMode = _PlayerChoosen;

							break;
						}
						case COMMANDS::_BotChoosen:
						{
							_SelectedMazeGameMode = _BotChoosen;

							break;
						}

						default:
							break;
						}

						break;
					}
					case WM_CLOSE:
					{
						DestroyWindow(hWnd);
						
						break;
					}

					default:
						break;
					}
					return DefWindowProc(hWnd, _playMsg, _wp, _lp);
			});
			_menu.SetPlay(_PlayResult.second);

			break;
		}

		case COMMANDS::OnDownLoadClicked:
		{
			if (_menu.GetDownload()) DestroyWindow(_menu.GetDownload());
			std::pair<bool, HWND> _DownLoadResult = _menu.AddWindow(L"DownloadWndClass", L"The Maze", _hWnd,
				[](HWND hWndDwLd, UINT _DownloadMsg, WPARAM _wp, LPARAM _lp) -> LRESULT {
					TheMazeWindow ma;

					switch (_DownloadMsg)
					{
					case WM_CREATE:
					{	
						SetWindowPos(hWndDwLd, HWND_TOPMOST, 0, 0, 1079, 1079, NULL);

						break;
					}
					case WM_PAINT:
					{
						if (_SelectedMazeGameMode == _PlayerChoosen || _SelectedMazeGameMode == NULL)
						{
							srand((unsigned)time(NULL));
							RECT _rect_3;
							GetClientRect(hWndDwLd, &_rect_3);
							PAINTSTRUCT _ps_3;
							HDC _hdc_3 = BeginPaint(hWndDwLd, &_ps_3);
							ma.draw(_hdc_3, hWndDwLd, _rect_3);
							EndPaint(hWndDwLd, &_ps_3);


						}
						else if (_SelectedMazeGameMode == _BotChoosen)
						{
							srand((unsigned)time(NULL));
							RECT _rect_3;
							GetClientRect(hWndDwLd, &_rect_3);
							PAINTSTRUCT _ps_3;
							HDC _hdc_3 = BeginPaint(hWndDwLd, &_ps_3);
							ma.draw(_hdc_3, hWndDwLd, _rect_3);
							EndPaint(hWndDwLd, &_ps_3);
						}
						
						break;
					}

					default:
						break;
					}
					return DefWindowProc(hWndDwLd, _DownloadMsg, _wp, _lp);
				});
			_menu.SetDownload(_DownLoadResult.second);

			break;
		}

		case COMMANDS::OnStatisticsClicked:
		{
			if (_menu.GetStatistics()) DestroyWindow(_menu.GetStatistics());
			std::pair<bool, HWND> _StatResult = _menu.AddWindow(L"StatWndClass", L"Statistics", _hWnd,
				[](HWND hWnd, UINT _statMsg, WPARAM _wp, LPARAM _lp) -> LRESULT {
					StatisticsWindow stat;
					
					switch (_statMsg)
					{
					case WM_CREATE:
					{
						stat.StatisticsWidget(hWnd);
						SetWindowPos(hWnd, HWND_TOPMOST, 300, 200, 900, 600, NULL);
						
						break;
					}

					default:
						break;
					}
					return DefWindowProc(hWnd, _statMsg, _wp, _lp);
			});
			_menu.SetStatistics(_StatResult.second);

			break;
		}

		case COMMANDS::OnSettingsClicked:
		{
			if (_menu.GetSettings()) DestroyWindow(_menu.GetSettings());
			std::pair<bool, HWND> _SettResult = _menu.AddWindow(L"SettWndClass", L"Settings", _hWnd,
				[](HWND hWnd, UINT _settMsg, WPARAM _wp, LPARAM _lp) -> LRESULT {
					switch (_settMsg)
					{
					case WM_CREATE:
					{
						
						
						break;
					}

					default:
						break;
					}
					return DefWindowProc(hWnd, _settMsg, _wp, _lp);
			});
			_menu.SetSettings(_SettResult.second);

			break;
		}
		case COMMANDS::OnExitClicked:
		{
			_menu.ExitApp();

			break;
		}
		default: 
		{ 
			break; 
		}
		}
		break;
	}
	case WM_CREATE:
	{
		_menu.AddMainMenu(_hWnd);

		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default: { return DefWindowProc(_hWnd, _message, _wp, _lp); }
	}
}

WNDCLASS NewWindowClass(HBRUSH _BGColor, HCURSOR _Cursor, HINSTANCE _hInst, HICON _Icon, LPCWSTR _Name, WNDPROC _Callback)
{
	WNDCLASS NWC = { 0 };

	NWC.hCursor = _Cursor;
	NWC.hInstance = _hInst;
	NWC.hIcon = _Icon;
	NWC.hbrBackground = _BGColor;
	NWC.lpfnWndProc = _Callback;
	NWC.lpszClassName = _Name;

	return NWC;
}


