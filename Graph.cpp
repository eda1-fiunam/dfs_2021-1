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


#include "Graph.hpp"

Graph::Graph()
{
	// nada (por el momento)
}

bool Graph::add_vertex( Vertex v )
{
	auto ret = vertices.insert( { v.get_name(), v } );
	// 'map' no permite duplicados, así que no hay necesidad de buscarlos
	
	return ret.second;
}

bool Graph::add_edge( std::string from, std::string to, Graph::Kind kind )
{
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( from );
	auto v2 = this->vertices.find( to );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() ){
		v1->second.add_neighbor( v2->second );

      if( kind == Graph::Kind::UNDIRECTED ) v2->second.add_neighbor( v1->second );

		return true;
	}

	return res;
}

void Graph::print()
{
	for( auto v : this->vertices ){
		std::cout << "\n" << v.second.get_name() << ": ";
		v.second.print_neighbors();
	}
	std::cout << "\n";
}

std::map<std::string, Vertex>* Graph::get_vertices()
{
	return &(this->vertices);
}

Vertex* Graph::get_vertex( std::string name )
{
	auto v = this->vertices.find( name );
	// .find() devuelve un iterador (apuntador) a la posición donde haya 
	// encontrado la coincidencia con la clave 'name'
	
	return &(v->second);
}

#ifdef DEBUG
// función auxiliar para imprimir el contenido de la cola
static void print_queue( std::deque<std::string> queue )
{
   std::cout << "El contenido de la cola es: ";
   for( auto q : queue ){
      std::cout << q << ", ";
   }
   std::cout << "\n";
}
#endif  

void Graph::bfs( std::string start )
{
}

void Graph::dfs( std::string start )
{

}

size_t Graph::dfs_recursive( Vertex* v, size_t time )
{

}




