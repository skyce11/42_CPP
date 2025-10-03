/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <migonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:12:30 by migonzal          #+#    #+#             */
/*   Updated: 2025/10/03 16:12:33 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Skyce");
	ClapTrap b("Madirex");

	a.attack("Madirex");
	b.takeDamage(0);

	b.attack("Skyce");
	a.takeDamage(0);

	a.beRepaired(5);
	b.beRepaired(3);

	return 0;
}