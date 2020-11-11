/*Copyright (C) 
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
// para declarar y procesar cadenas

#include "Vertex.hpp"
#include "Graph.hpp"


int main()
{
	std::array<std::string, 11> vertices = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K" };
	// std::array son como los arreglos estáticos nativos de C, [], pero con esteroides.
	// También existen los arreglos dinámicos: std::vector

	std::array<std::string, 11> edges = { "AE", "AB", "BC", "BF", "DH", "EI", "FG", "FI", "GJ", "GK", "HK" };
	// primero escribí las conexiones, luego las conté, y finalmente, escribí el '11'.
	// Como este ejemplo es de un grafo no dirigido, resulta que "AE" es lo mismo que
	// "EA", por eso no es necesario duplicar la conexión.

	Graph g;

	for( auto& v : vertices ){ g.add_vertex( Vertex( v ) ); }

	for( auto& e : edges ){ g.add_edge( e.substr( 0, 1 ), e.substr( 1, 1 ) ); }
	// .substr( a_partir_de_dónde, cuántos_queremos_leer )

	g.bfs( "A" );
}
