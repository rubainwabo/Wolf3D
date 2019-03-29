/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:10:24 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/29 21:46:22 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define WIN_W (WIDTH - WIDTH_MM)
#define WIN_H (HEIGHT - HEIGHT_MM)

// static void 	intersection_hor(t_wolf3d *w)
// {
//
// }
// static void 	intersection_ver(t_wolf3d *w)
// {
//
// }
static int 	fintersection(t_wolf3d *w, int iteration)
{
	float			angle;
	int 			mapx;
	int 			mapy;
	unsigned int 	length;
	t_vec2f			dir;

	angle = (w->cam->angle + (w->cam->fov / 2) - (iteration * w->cam->fov / WIN_W));
	dir.x = tCos(angle);
	dir.y = tSin(angle);
	length = -1;
	while (++length < w->cam->raylength)
	{
		mapx = (int)(w->cam->position.x + (length * dir.x));
		mapy = (int)(w->cam->position.y + (length * dir.y));

		if ((mapy / BLOC_SIZE < w->map->h && w->map->board[mapy / BLOC_SIZE][mapx / BLOC_SIZE]))
		{
			w->cam->intersection.x = mapx;
			w->cam->intersection.y = mapy;
			return (1);
		}
	}
	return (0);

}

void 	projection3D(t_wolf3d *w)
{

	int 		i;
	double		wall_h;
	double		perpdistwall;
	double		dist_w;
	double		dist_c;
	double		cam_h;
	double		h_seen;
	int 		y;
	int			hit;

	//t_point		dir;

	wall_h = 1000.0;
	cam_h = 500.0;
	dist_c = 50.0;
	//perpdistwall = WIN_W / tTan(30.0);
	i = -1;
	while (++i < WIN_W)
	{
		w->cam->rays[i].startPoint = w->cam->position;
		w->cam->rays[i].startPoint.color = 0xff0000;
		w->cam->rays[i].endPoint.color = 0xff0000;

		if ((hit = fintersection(w, i)))
			w->cam->rays[i].endPoint = w->cam->intersection;
		else
		{
			w->cam->rays[i].endPoint.x = w->cam->position.x + w->cam->raylength * tCos((w->cam->angle + w->cam->fov / 2) - (i * (w->cam->fov / WIN_W)));
			w->cam->rays[i].endPoint.y = w->cam->position.y + w->cam->raylength * tSin((w->cam->angle + w->cam->fov / 2) - (i * (w->cam->fov / WIN_W)));
		}
		perpdistwall = sqrt(pow((w->cam->position.x - w->cam->rays[i].endPoint.x), 2) + pow((w->cam->position.y - w->cam->rays[i].endPoint.y), 2));
		dist_w =  perpdistwall * tCos(30.0);
		h_seen = dist_c * wall_h / dist_w;
		y = cam_h - (h_seen / 2) - 1;
		if (hit == 1)
			while (++y < (cam_h + (h_seen / 2)))
				put_pixel_img(w, i + WIDTH_MM, y + 250, 0xff0000);
	}
}
