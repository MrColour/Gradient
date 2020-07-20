/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2020/07/20 02:09:52 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <stdio.h>

# include <SDL_image.h>

# include "structs.h"
# include "window_config.h"

void		SDLU_start(t_display *dest);
void		SDLU_close(t_display *display);

// SDL_Rect	*carve__texture(void);

void		process_user_input(t_app_context *app_state);
void		update_app_state(t_app_context *app_state);

// void		itow(int n, SDL_Rect dest, t_display *dislay);

#endif
