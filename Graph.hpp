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

#pragma once

#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
// para declarar y procesar cadenas

#include <list>
// para los arreglos []

#include <map>
// para los diccionarios (tablas hash)

#include "Vertex.hpp"
// la clase Graph _usa_ a la clase Vertex

#include <deque>

class Graph
{
private:
	mutable std::map<std::string, Vertex> vertices; 
	// asociamos un vértice (value) a una cadena (key):
	// vertices[ string ] = a_vertex

   void dfs_recursive( Vertex* v, size_t time );
   // ejecuta la parte recursiva del algoritmo. Es privada porque el cliente de
   // la clase NO tiene que saber, incluso, que existe.

public:
   enum class Kind { UNDIRECTED, DIRECTED };

	Graph();
//	Graph( std::vector<Vertex> vertices ); 

	bool add_vertex( Vertex v );

   // TODO: Si el segundo, o ambos vértices no existen, entonces los crea.
	bool add_edge( std::string from, std::string to, Graph::Kind kind = Graph::Kind::UNDIRECTED );

	std::map<std::string, Vertex> *get_vertices();
	// devuelve la "lista" de vértices (en realidad es una tabla hash, pero la podemos pensar de esa manera)

	Vertex* get_vertex( std::string name );
	// devuelve el valor asociado a la clave 'name'; no queremos exponer que es un 'map'

	void print();

	void bfs( std::string name );

   void dfs( std::string name );
};
