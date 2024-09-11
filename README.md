# Coalition-Race

The **Coalition-Race** is a C++ simulation of a coalition-building game in which multiple agents from different parties compete to form a 61-mandate coalition as quickly as possible. The simulation uses a graph-based model to represent parties, collaborations, and similarity scores.

## Objective

Design an object-oriented system in C++ to simulate coalition formation. Key objectives include efficient memory handling and avoiding memory leaks.

## Implementation

* **Graph Representation:**
   * **Vertices:** Parties
   * **Edges:** Collaborations between parties, with similarity scores as weights
* **Configuration:**
   * Input is provided via a JSON config file detailing parties, the graph, and agents.
* **Simulation Flow:**
   * **Parties:** Transition through states (Waiting, CollectingOffers, Joined) based on offers and policies.
   * **Agents:** Offer neighboring parties to join coalitions based on selection policies.
   * **Policies:** Implemented for selection and joining strategies.

## Classes

* **Parser:** Parses JSON to `Simulation` objects and vice versa.
* **Simulation:** Manages resources and simulation steps.
* **Graph:** Represents the party collaboration graph using an adjacency matrix.
* **Party:** Manages party state and coalition joining.
* **Agent:** Manages party offers and coalition recruitment.
* **SelectionPolicy & JoinPolicy:** Abstract classes defining strategy algorithms for agent actions and party decisions.

## Program Flow

1. **Initialization:** Parse the config file to create a `Simulation` object.
2. **Iteration:** Update the simulation state and perform steps for each party and agent.
3. **Termination:** The simulation ends when a coalition reaches 61 mandates or all parties join a coalition.

## Configuration File

* JSON format includes parties, graph adjacency matrix, and agents with their policies.

## Output

* Results are written to a `.out` file in JSON format.
