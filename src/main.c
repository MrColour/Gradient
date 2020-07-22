/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/21 18:52:35 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	app_context_initialize(t_app_context *app_state, t_display *display)
{
	app_state->active = true;
	app_state->app_over = false;

	app_state->min = 0;
	app_state->max = 100;

	app_state->capacity = 10;
	app_state->curve_count = 0;

	app_state->curves = calloc(sizeof(*(app_state->curves)), app_state->capacity);

	app_state->gradient = calloc(sizeof(*(app_state->gradient)), BAR_WIDTH);

	(void)display;
}

int	main(void)
{
	t_display		display;
	t_app_context	app_state;

	SDLU_start(&display);
	app_context_initialize(&app_state, &display);
	// memset(app_state.gradient, 255, sizeof(*(app_state.gradient)) * BAR_WIDTH);

	SDL_StartTextInput();
	// SDL_SetTextInputRect

	app_state.curve_count = 3;

	app_state.curves[0].s_color = 0xFF0000;
	app_state.curves[1].s_color = 0x33FF00;
	app_state.curves[2].s_color = 0x00FF00;
	app_state.curves[3].s_color = 0x00FFFF;

	app_state.curves[0].start =  90;
	app_state.curves[1].start = 0;
	app_state.curves[2].start = 250;
	app_state.curves[3].start = 300;

	while (app_state.active == true)
	{
		process_user_input(&app_state);

		update_app_state(&app_state);

		draw_bar(app_state.gradient, &display, 0);

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);

	}
	SDLU_close(&display);
	return (0);
}
