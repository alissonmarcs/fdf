/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:46:38 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/16 11:34:31 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

#define REAL_NUMBER 0.40824829

typedef struct s_row
{
	float				x;
	float				y;
	float				z;
}						t_row;

typedef struct s_matrix
{
	t_row				row_1;
	t_row				row_2;
	t_row				row_3;
}						t_matrix;

t_matrix matrice = (t_matrix)
{
	{1.732050808 * REAL_NUMBER, 0, -1.732050808 * REAL_NUMBER},
	{REAL_NUMBER, 2 * REAL_NUMBER, REAL_NUMBER},
	{1.414213562 * REAL_NUMBER, -1.414213562 * REAL_NUMBER, 1.414213562}
};

void transform(t_fdf *fdf, t_point *point)
{
	t_point new;

	new.x = matrice.row_1.x * point->x + matrice.row_1.y * point->y + matrice.row_1.z * (point->z * fdf->cam->z_scale);
	new.y = (matrice.row_2.x * point->x) + (matrice.row_2.y * point->y) + (matrice.row_2.z * (point->z * fdf->cam->z_scale));
	
	point->x = new.x;
	point->y = new.y;
}
