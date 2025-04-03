/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 02:06:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/04/03 02:06:46 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
		
	public:
		Brain();
		Brain(Brain const &src);
		Brain &operator=(const Brain &rhs);
		virtual ~Brain();

		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif