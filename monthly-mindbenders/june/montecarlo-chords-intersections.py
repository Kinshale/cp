import itertools
import math
import random


def generate_random_chord():
    a = random.uniform(0, 2 * math.pi)
    b = random.uniform(0, 2 * math.pi)
    return min(a, b), max(a, b)


def do_chords_intersect(c1, c2):
    (a1, b1), (a2, b2) = c1, c2
    return (a1 < a2 < b1) != (a1 < b2 < b1)


def simulate_interections(num_chords=100):
    chords = [generate_random_chord() for _ in range(num_chords)]
    interesctions = 0

    for c1, c2 in itertools.combinations(chords, 2):
        if do_chords_intersect(c1, c2):
            interesctions += 1
    return interesctions


trials = 10_000
total_intersections = sum(simulate_interections(100) for _ in range(trials))
expected_value = total_intersections / trials

print(f"Simulated Expected Intersections: {expected_value:.2f}")
