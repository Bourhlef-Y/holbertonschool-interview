#!/usr/bin/python3
"""
N Queens problem solver
"""
import sys


def is_safe(board, row, col):
    """
    Check if a queen can be placed at position (row, col)
    without attacking any other queen
    """
    # Check row on left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    # Check lower diagonal on left side
    i, j = row, col
    while i < len(board) and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1

    return True


def solve_nqueens_util(board, col, solutions):
    """
    Recursive utility function to solve N Queens problem
    """
    n = len(board)
    # Base case: If all queens are placed
    if col >= n:
        solution = []
        for i in range(n):
            for j in range(n):
                if board[i][j] == 1:
                    solution.append([i, j])
        solutions.append(solution)
        return

    # Try placing queen in each row of current column
    for i in range(n):
        if is_safe(board, i, col):
            # Place the queen
            board[i][col] = 1
            
            # Recur to place rest of the queens
            solve_nqueens_util(board, col + 1, solutions)
            
            # Backtrack
            board[i][col] = 0


def solve_nqueens(n):
    """
    Solve the N Queens problem and return all solutions
    """
    # Initialize the board
    board = [[0 for _ in range(n)] for _ in range(n)]
    solutions = []
    
    # Start solving from column 0
    solve_nqueens_util(board, 0, solutions)
    
    return solutions


if __name__ == "__main__":
    # Check command line arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    
    # Solve and print solutions
    solutions = solve_nqueens(n)
    for solution in solutions:
        print(solution)
